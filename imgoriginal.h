#ifndef IMGORIGINAL_H
#define IMGORIGINAL_H

#include <QString>
#include <vtkImageData.h>
#include <vtkImageReader.h>
#include <vtkPNGReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkImageThreshold.h>
#include <vtkImageCanvasSource2D.h>


class ImgOriginal
{
    public:
        ImgOriginal();
        vtkSmartPointer<vtkRenderer> GetRenderer();
        void Update();
        void setFilename(QString);

    private:
        QString filename;
        vtkSmartPointer<vtkPNGReader> head_reader;
        vtkSmartPointer<vtkImageViewer2> imageViewer_original;
        vtkSmartPointer<vtkRenderWindow> renwin_original;
        vtkSmartPointer<vtkRenderWindowInteractor> renwinin_original;
        vtkSmartPointer<vtkRenderer> renderer_original;

};

#endif // IMGORIGINAL_H
