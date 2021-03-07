/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef CONFIGFORM_H
#define CONFIGFORM_H

#include <QWidget>
#include "protocol/messagefactory.h"
#include <QPointer>

namespace Ui {
class ConfigForm;
}

class MessageFactory;

class ConfigForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigForm(QWidget *parent = nullptr);
    ~ConfigForm();
protected:
    void updateUI();
protected slots:
    void initCAN1ButtonClicked();
    void initCAN2ButtonClicked();
private:
    Ui::ConfigForm *ui;
    MessageFactory* messageFactory;
};

#endif // CONFIGFORM_H
