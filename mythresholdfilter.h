#ifndef MYTHRESHOLDFILTER_H
#define MYTHRESHOLDFILTER_H

#include <vtkSimpleImageToImageFilter.h>

class MyThresholdFilter : public vtkSimpleImageToImageFilter
{
    public:
        static MyThresholdFilter *New(); //Requerido por VTK
        void setThreshold(unsigned short val);
        unsigned short getThreshold();

    protected:
        void SimpleExecute(vtkImageData *input, vtkImageData *output);

    private:
        unsigned short minThresh;
        unsigned short maxthresh;
        unsigned short threshold;
};

#endif // MYTHRESHOLDFILTER_H
