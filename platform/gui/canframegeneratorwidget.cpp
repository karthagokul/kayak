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

CANFrameGeneratorWidget::CANFrameGeneratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANFrameGeneratorWidget)
{
    ui->setupUi(this);
}

CANFrameGeneratorWidget::~CANFrameGeneratorWidget()
{
    delete ui;
}
