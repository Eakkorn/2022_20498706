#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include "optiondialog.h"
#include <QFileInfo>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkNew.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
   
    ui->widget1->setRenderWindow(renderWindow);
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow ->AddRenderer(renderer);
    vtkNew<vtkCylinderSource> cylinder;
    cylinder -> SetResolution(8);
    vtkNew<vtkPolyDataMapper> cylinderMapper;
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());
    vtkNew<vtkActor> cylinderActor;
    cylinderActor ->SetMapper(cylinderMapper);
    cylinderActor ->GetProperty()->SetColor(1., 0., 0.35);
    cylinderActor ->RotateX(30.0);
    cylinderActor ->RotateY(-45.0);

    renderer->AddActor(cylinderActor);

    renderer -> ResetCamera();
    renderer -> GetActiveCamera()->SetPosition(0, 0, 10);
    renderer -> GetActiveCamera()->SetFocalPoint(0, 0, 0);
    renderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    renderer -> ResetCameraClippingRange();

    


    connect( ui->pushButton, &QPushButton :: released , this , &MainWindow :: handleButton );
    connect( ui->pushButton_2, &QPushButton :: released , this , &MainWindow :: handleButton );
    connect ( this, &MainWindow :: statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage );

    /* Create / allocate the ModelList */
        this->partList=new ModelPartList("PartsList");

        /* Link i t to the t r e evi ew in the GUI */
        ui->treeView->setModel(this->partList);

        /* Manually c r e a t e a model t r e e = the r e a much b e t t e r and more f l e x i b l e ways o f doing
        this ,
        e.g. with nested functions . This is just a quick example as astarting point . */
        ModelPart* rootItem=this->partList->getRootItem( );

        /* Add 3 top level items */
        for(int i=0;i<3;i++){
            QString name=QString( "TopLevel %1").arg(i);
            QString visible("true");

            /* Create child item */
            ModelPart* childItem=new ModelPart({name, visible});

            /* Append to t r e e top=l e v e l */
            rootItem->appendChild(childItem);

            /* Add 5 sub=i tems */
            for(int j=0;j<5;j++){
                QString name=QString("Item %1,%2").arg(i).arg(j);
                QString visible("true");

                ModelPart* childChildItem=new ModelPart({name, visible});

                /* Append to parent */
                childItem->appendChild(childChildItem);
            }
        }

       connect( ui->treeView, &QTreeView :: clicked , this ,&MainWindow :: handleTreeClicked );


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow :: handleButton ( ) {
    QMessageBox msgBox ;
    msgBox.setText ( "Add button was clicked" );
    msgBox.exec( );
    emit statusUpdateMessage ( QString("Add button was clicked"), 0);
}
void MainWindow::handleTreeClicked(){
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());
    QString text = selectedPart->data(0).toString();
    emit statusUpdateMessage(QString("The selected item is: ")+text, 0);
}
void MainWindow::on_actionOpen_File_triggered() {
    QModelIndex index = ui->treeView->currentIndex();
    ModelPart* selectedPart = static_cast<ModelPart*>(index.internalPointer());
    QString text = selectedPart->data(0).toString();
    emit statusUpdateMessage(QString("Open File acion triggered"), 0);
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C:\\",
        tr("STL Files(*.stl);;Text Files(*txt)"));

    emit statusUpdateMessage(QString("File Name: ") + fileName, 0);
    OptionDialog dialog(this);
    QFileInfo info(fileName);
    QString FileNameNoPath = info.fileName();
    selectedPart->set(0, FileNameNoPath);
    QModelIndex selectedIndex, newIndex;
    selectedIndex = ui->treeView->currentIndex();
    newIndex = partList->appendChild(selectedIndex, { fileName , "True" });
    
    selectedPart->loadSTL(fileName);
    
    
    return;
}



void MainWindow::on_pushButton_2_clicked(){
    OptionDialog dialog(this);

 if (dialog.exec() == QDialog::Accepted) {
     emit statusUpdateMessage(QString("Dialog accepted "), 0);
 } else {
     emit statusUpdateMessage(QString("Dialog rejected "), 0);
}
}


void MainWindow::on_actionItem_Options_triggered()
{
    ui->treeView->addAction(ui->actionItem_Options);
}




