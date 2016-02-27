#include "imgisovol.h"

#include "mythresholdfilter.h"

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkVolume16Reader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkOutlineFilter.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkPolyDataNormals.h>
#include <vtkContourFilter.h>
#include <vtkSmartPointer.h>


ImgIsoVol::ImgIsoVol(){
      renderer_isovol = vtkSmartPointer<vtkRenderer>::New();
      contourExtractor = vtkSmartPointer<vtkContourFilter>::New();
      contourNormals = vtkSmartPointer<vtkPolyDataNormals>::New();
      contourMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
      contour = vtkSmartPointer<vtkActor>::New();
      contour_gsmooth = vtkSmartPointer<vtkImageGaussianSmooth>::New();
      aCamera = vtkSmartPointer<vtkCamera>::New();
}

void ImgIsoVol::SetFilter(MyThresholdFilter *mf){
    this->myFilter=mf;
}


void ImgIsoVol::Update(){

    contour_gsmooth->SetInputConnection(myFilter->GetOutputPort());

    contourExtractor->SetInputConnection(contour_gsmooth->GetOutputPort());
    contourExtractor->SetValue(0, 128);

    contourNormals->SetInputConnection(contourExtractor->GetOutputPort());
    contourNormals->SetFeatureAngle(60.0);

    contourMapper->SetInputConnection(contourNormals->GetOutputPort());
    contourMapper->ScalarVisibilityOff();

    contour->SetMapper(contourMapper);

    aCamera->SetViewUp (0, 0, -1);
    aCamera->SetPosition (0, 1, 0);
    aCamera->SetFocalPoint (0, 0, 0);
    aCamera->ComputeViewPlaneNormal();
    aCamera->Azimuth(30.0);
    aCamera->Elevation(30.0);

    renderer_isovol->AddActor(contour);
    renderer_isovol->SetActiveCamera(aCamera);
    renderer_isovol->ResetCamera();
    aCamera->Dolly(1.5);

    renderer_isovol->SetBackground(.2, .3, .4);
    renderer_isovol->ResetCameraClippingRange ();
    renderer_isovol->ResetCamera ();
}

vtkSmartPointer<vtkRenderer> ImgIsoVol::GetRenderer(){
    return renderer_isovol;
}


