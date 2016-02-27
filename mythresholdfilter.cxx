#include "mythresholdfilter.h"

#include <vtkImageData.h>
#include <vtkObjectFactory.h>

#include "mythresholdfilter.h"

//Definir el metodo *New con el macro de VTK
vtkStandardNewMacro(MyThresholdFilter);

void MyThresholdFilter::setThreshold(unsigned short val){
    cout << ("MyThresholdFilter::setThreshold");
    this->threshold=val;
}

unsigned short MyThresholdFilter::getThreshold(){
    cout << ("MyThresholdFilter::getThreshold()");
    return threshold;
}

void MyThresholdFilter::SimpleExecute(vtkImageData *input, vtkImageData *output){
    cout << ("Entra al MyThresholdFilter::SimpleExecute");
    //Codigo de mi filtro aqui
    unsigned short *pixelin=NULL;
    unsigned short *pixelout=NULL;
    int ext[6];
    output->GetExtent(ext);
    int i=0, j=0, k=0;
    for (i = 0; i< ext[1]; i++) {
        for (j = 0; j < ext[3]; j++) {
            for (k = 0; k < ext[5]; k++) {
                pixelin = static_cast<unsigned short*>(input->GetScalarPointer(i,j,k));
                pixelout = static_cast<unsigned short*>(output->GetScalarPointer(i,j,k));

                //if(pixelin[0]>=threshold)
                if(pixelin[0]>=50)
                    pixelout[0]=255;
                else
                    pixelout[0]=0;
            }
        }
    }

}


