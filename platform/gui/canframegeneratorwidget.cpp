/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#include "canframegeneratorwidget.h"
#include "ui_canframegeneratorwidget.h"
#include "protocol/messagefactory.h"
#include <QDebug>
CANFrameGeneratorWidget::CANFrameGeneratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANFrameGeneratorWidget)
{
    ui->setupUi(this);
    MessageFactory fc;
}

CANFrameGeneratorWidget::~CANFrameGeneratorWidget()
{
    delete ui;
}
