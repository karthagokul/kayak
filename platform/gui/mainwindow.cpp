#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMdiSubWindow>

#include "canlogform.h"
#include "configform.h"
#include "canframegeneratorwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
    connect(ui->actionCan_Log,SIGNAL(triggered()),this,SLOT(showCanLogView()));
    connect(ui->actionCAN_Settings,SIGNAL(triggered()),this,SLOT(showCanSettings()));
    connect(ui->actionCAN_Generator,SIGNAL(triggered()),this,SLOT(showCanFrameGenerator()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSubWindow(QWidget *widget)
{
    QMdiSubWindow* subWindow=mdiArea->addSubWindow(widget);
    subWindow->setFixedSize(widget->size());
    widget->show();
}
void MainWindow::showCanSettings()
{
    qDebug()<<"Showing CAN Settings view";
    ConfigForm *form= new ConfigForm(mdiArea);
    addSubWindow(form);

}

void MainWindow::showCanFrameGenerator()
{
    qDebug()<<"Showing CAN FrameGenerator";
    CANFrameGeneratorWidget *form= new CANFrameGeneratorWidget(mdiArea);
    addSubWindow(form);
}

void MainWindow::showCanLogView()
{
    qDebug()<<"Showing CAN log view";
    CANLogForm *form= new CANLogForm(mdiArea);
    addSubWindow(form);
}
