#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

#include "mythresholdfilter.h"
#include "imgoriginal.h"
#include "imgthresh.h"
#include "imgisovol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_file_clicked();
    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
    QString string_filename;

    ImgOriginal *myImgOriginal;
    ImgThresh *myImgThresh;
    ImgIsoVol *myImgIsoVol;


};

#endif // MAINWINDOW_H
