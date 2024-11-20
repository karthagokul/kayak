/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
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
