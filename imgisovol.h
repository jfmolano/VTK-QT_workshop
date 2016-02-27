#ifndef IMGISOVOL_H
#define IMGISOVOL_H

#include <QString>
#include <vtkImageData.h>
#include <vtkImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkImageThreshold.h>

#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkOutlineFilter.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkPolyDataNormals.h>
#include <vtkContourFilter.h>
#include <vtkSmartPointer.h>
#include <vtkImageGaussianSmooth.h>

#include "mythresholdfilter.h"


class ImgIsoVol
{
    public:
        ImgIsoVol();
        void Update();
        void setFilename(QString);
        void SetFilter(MyThresholdFilter*);
        vtkSmartPointer<vtkRenderer> GetRenderer();

    private:
        QString filename;
        unsigned short threshold;
        vtkSmartPointer<vtkRenderer> renderer_isovol;
        vtkSmartPointer<vtkContourFilter> contourExtractor;
        vtkSmartPointer<vtkPolyDataNormals> contourNormals;
        vtkSmartPointer<vtkPolyDataMapper> contourMapper;
        vtkSmartPointer<vtkActor> contour;
        vtkSmartPointer<vtkImageGaussianSmooth> contour_gsmooth;
        vtkSmartPointer<vtkCamera> aCamera;

        MyThresholdFilter *myFilter;

};

#endif // IMGISOVOL_H
