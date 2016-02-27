#ifndef IMGTHRESH_H
#define IMGTHRESH_H

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
#include <vtkPNGReader.h>
#include "mythresholdfilter.h"


class ImgThresh
{
    public:
        ImgThresh();
        void Update();
        void setFilename(QString);
        void setThreshold(unsigned short);
        vtkSmartPointer<vtkRenderer> GetRenderer();
        MyThresholdFilter* GetResultFilter();

    private:
        QString filename;
        unsigned short threshold;
        vtkSmartPointer<vtkPNGReader> head_reader;
        vtkSmartPointer<vtkImageViewer2> imageViewer_thresh;
        vtkSmartPointer<vtkRenderWindowInteractor> renwinin_thresh;
        vtkSmartPointer<vtkRenderer> renderer_thresh;
        MyThresholdFilter *myFilter;

};

#endif // IMGTHRESH_H
