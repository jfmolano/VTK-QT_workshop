#include "imgoriginal.h"

ImgOriginal::ImgOriginal(){

    head_reader = vtkSmartPointer<vtkPNGReader>::New();
    head_reader->SetFileName("/home/estudiante/Downloads/GokuAfterFightingVegetaBuuSaga.png");

    imageViewer_original = vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer_original->SetInputConnection(head_reader->GetOutputPort());

    renwinin_original = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer_original->SetupInteractor(renwinin_original);

    renderer_original = imageViewer_original->GetRenderer();
    renderer_original->ResetCamera();
}

void ImgOriginal::Update(){

    head_reader->SetFileName(this->filename.toStdString().c_str());
    head_reader->Update();
    renderer_original->ResetCamera();
}

vtkSmartPointer<vtkRenderer> ImgOriginal::GetRenderer(){
    return renderer_original;
}

void ImgOriginal::setFilename(QString name){
    this->filename=name;
}

