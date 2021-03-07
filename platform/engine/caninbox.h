/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef CANINBOX_H
#define CANINBOX_H

#include <QThread>
#include "protocol/message.h"

class CANInbox : public QThread
{
public:
    CANInbox();

private:
};

#endif // CANINBOX_H
