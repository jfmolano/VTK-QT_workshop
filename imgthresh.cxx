#include "imgthresh.h"
#include "mythresholdfilter.h"


#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkOutlineFilter.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkPolyDataNormals.h>
#include <vtkContourFilter.h>
#include <vtkSmartPointer.h>

ImgThresh::ImgThresh(){

    head_reader = vtkSmartPointer<vtkImageReader>::New();
    head_reader->ReleaseDataFlagOff();
    head_reader->SetDataByteOrderToLittleEndian();
    head_reader->SetDataExtent(0, 255, 0, 255, 1, 93);
    head_reader->SetDataMask(0x7fff);
    head_reader->SetDataScalarTypeToUnsignedShort();

    myFilter= MyThresholdFilter::New();
    myFilter->SetInputConnection(head_reader->GetOutputPort());

    imageViewer_thresh = vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer_thresh->SetInputConnection(myFilter->GetOutputPort());

    renwinin_thresh = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renwinin_thresh->Initialize();
    renwinin_thresh->Start();
    imageViewer_thresh->SetupInteractor(renwinin_thresh);

    renderer_thresh = imageViewer_thresh->GetRenderer();
    renderer_thresh->ResetCamera();
}

void ImgThresh::Update(){

    head_reader->SetFilePrefix(this->filename.toStdString().c_str());
    head_reader->Update();
    myFilter->setThreshold(this->threshold);
    myFilter->Update();
    renderer_thresh->ResetCamera();
}

void ImgThresh::setFilename(QString name){
    this->filename=name;
}

void ImgThresh::setThreshold(unsigned short t){
    this->threshold=t;
}

vtkSmartPointer<vtkRenderer> ImgThresh::GetRenderer(){
    return renderer_thresh;
}

MyThresholdFilter* ImgThresh::GetResultFilter(){
    return myFilter;
}

