/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include "message.h"
#include "reqcmdmessage.h"
#include <QPointer>

enum BaudRate {
    BaudRate125kbps=1,
    BaudRate250kbps,
    BaudRate500kbps,
    BaudRate1000kbps
};

class MessageFactory
{
public:
    MessageFactory();
    QSharedPointer<Message> createMessage(const QByteArray &inputdata);
    Message* createReqCMD_initCAN(const QString & canId,const BaudRate& baudRate,const QByteArray &data);
};



#endif // MESSAGEFACTORY_H
