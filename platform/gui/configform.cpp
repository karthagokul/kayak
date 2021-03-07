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

ConfigForm::ConfigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigForm)
{
    ui->setupUi(this);
    updateUI();
}

void ConfigForm::updateUI()
{
    ui->comport_combo->addItems(KayakEngine::instance()->getCOMDevices());
    ui->baudrate_combo->addItems(KayakEngine::instance()->getCOMBaudRate());
}

ConfigForm::~ConfigForm()
{
    delete ui;
}
