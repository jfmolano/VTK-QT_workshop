#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgoriginal.h"
#include <QFileDialog>

#include <vtkImagePlaneWidget.h>
#include "mythresholdfilter.h"
#include <vtkImageThreshold.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myImgOriginal = new ImgOriginal();
    myImgThresh = new ImgThresh();
    myImgIsoVol = new ImgIsoVol();


    this->ui->qvtkwidget_original->GetRenderWindow()->AddRenderer(
                myImgOriginal->GetRenderer());

    this->ui->qvtkwidget_threshold->GetRenderWindow()->AddRenderer(
                myImgThresh->GetRenderer());

    //this->ui->qvtkwidget_mcubes->GetRenderWindow()->AddRenderer(
                //myImgIsoVol->GetRenderer());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_file_clicked()
{
    //QString name="/headsq";
    QString dir = QFileDialog::getOpenFileName(this, tr("Open Directory"),
                 "/home");
    //dir.append(name);
    ui->lineEdit_file->setText(dir);
    //this->string_filename="/home/estudiante/Downloads/GokuAfterFightingVegetaBuuSaga2.png";
    this->string_filename=dir;
}

void MainWindow::on_pushButton_update_clicked()
{
    myImgThresh->setThreshold(this->ui->lineEdit_thresh->text().toShort());
    myImgThresh->setFilename(this->string_filename);
    myImgOriginal->setFilename(this->string_filename);
    myImgOriginal->Update();
    //cout << (this->string_filename.toStdString().c_str()+'\n');
    /*
    myImgIsoVol->SetFilter(myImgThresh->GetResultFilter());
    myImgIsoVol->Update();*/
    myImgThresh->Update();

}


