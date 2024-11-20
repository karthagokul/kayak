/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "configform.h"
#include "ui_configform.h"
#include "engine.h"
#include <QDebug>
#include "canoutbox.h"


ConfigForm::ConfigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigForm)
{
    messageFactory=new MessageFactory();
    ui->setupUi(this);
    updateUI();
}

void ConfigForm::updateUI()
{
    ui->comport_combo->addItems(KayakEngine::instance()->getCOMDevices());
    ui->baudrate_combo->addItems(KayakEngine::instance()->getCOMBaudRate());
    connect(ui->initCAN1Button, &QPushButton::clicked, this, &ConfigForm::initCAN1ButtonClicked);
    connect(ui->initCAN2Button, &QPushButton::clicked, this, &ConfigForm::initCAN2ButtonClicked);
}

void ConfigForm::initCAN1ButtonClicked()
{
    qDebug()<<"initCAN1ButtonClicked";
    BaudRate b=BaudRate125kbps;
    QByteArray data;
    QString canid="123";


    CANOutbox *outbox=new CANOutbox();
    //testing purpose

    outbox->post (messageFactory->createReqCMD_initCAN(canid,b,data));

}
void ConfigForm::initCAN2ButtonClicked()
{
    qDebug()<<"initCAN2ButtonClicked";
}

ConfigForm::~ConfigForm()
{
    delete ui;
}
