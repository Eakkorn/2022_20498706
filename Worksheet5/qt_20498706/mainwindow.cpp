#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->pushButton, &QPushButton :: released , this , &MainWindow :: handleButton );
    connect( ui->pushButton_2, &QPushButton :: released , this , &MainWindow :: handleButton );
    connect ( this,&MainWindow :: statusUpdateMessage,
                            ui->statusbar, &QStatusBar::showMessage );
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
    emit statusUpdateMessage( QString("Open File acion triggered" ), 0);
}
