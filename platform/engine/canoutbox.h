/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#ifndef CANOUTBOX_H
#define CANOUTBOX_H

#include <QThread>
#include <QMutex>
#include <QQueue>
#include "protocol/message.h"

class CANOutbox : public QThread
{
public:
    CANOutbox();
    void post(Message *message);
    void run();

private:
    QQueue<Message*> message_queue;
    QMutex resource;
};

#endif // CANOUTBOX_H
