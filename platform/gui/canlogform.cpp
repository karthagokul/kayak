/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "canlogform.h"
#include "ui_canlogform.h"

CANLogForm::CANLogForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANLogForm)
{
    ui->setupUi(this);
}

CANLogForm::~CANLogForm()
{
    delete ui;
}
