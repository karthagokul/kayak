/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef CANFRAMEGENERATORWIDGET_H
#define CANFRAMEGENERATORWIDGET_H

#include <QWidget>

namespace Ui {
class CANFrameGeneratorWidget;
}

class CANFrameGeneratorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CANFrameGeneratorWidget(QWidget *parent = nullptr);
    ~CANFrameGeneratorWidget();

private:
    Ui::CANFrameGeneratorWidget *ui;
};

#endif // CANFRAMEGENERATORWIDGET_H
