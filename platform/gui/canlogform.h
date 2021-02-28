/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef CANLOGFORM_H
#define CANLOGFORM_H

#include <QWidget>

namespace Ui {
class CANLogForm;
}

class CANLogForm : public QWidget
{
    Q_OBJECT

public:
    explicit CANLogForm(QWidget *parent = nullptr);
    ~CANLogForm();

private:
    Ui::CANLogForm *ui;
};

#endif // CANLOGFORM_H
