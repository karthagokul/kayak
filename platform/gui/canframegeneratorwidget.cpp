/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "canframegeneratorwidget.h"
#include "ui_canframegeneratorwidget.h"
#include "protocol/messagefactory.h"
#include "protocol/reqcmdmessage.h"
#include <QDebug>
CANFrameGeneratorWidget::CANFrameGeneratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANFrameGeneratorWidget)
{
    ui->setupUi(this);
    MessageFactory fc;
    QSharedPointer<Message> message=fc.createMessage ("Welcome Back");
    qDebug()<<message->getHeader();
}

CANFrameGeneratorWidget::~CANFrameGeneratorWidget()
{
    delete ui;
}
