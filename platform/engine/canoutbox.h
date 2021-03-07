/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef CANOUTBOX_H
#define CANOUTBOX_H

#include <QThread>


class CANOutbox : public QThread
{
public:
    CANOutbox();

private:
};

#endif // CANOUTBOX_H
