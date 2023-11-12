#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FileHandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filePatch= QCoreApplication::applicationDirPath();
    QString fileName="TestIniFile";
    QString fileContent = "Content of file";
    FileHandler fileHandler(eFileType::ini,filePatch, fileName);
    fileHandler.SaveStringAsFile(fileContent);
    QString fileContent2 =fileHandler.LoadFileAsString();
    if(fileContent==fileContent2)
    {
        qDebug()<<fileContent;
    }
}

