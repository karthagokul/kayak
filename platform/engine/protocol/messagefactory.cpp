/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "messagefactory.h"


MessageFactory::MessageFactory()
{

}

QSharedPointer<Message> MessageFactory::createMessage(const QByteArray &inputdata)
{
    QSharedPointer<Message> pB = QSharedPointer<Message>(new REQCMDMessage());
    return pB;
}

Message* MessageFactory::createReqCMD_initCAN(const QString & canId,const BaudRate& baudRate,const QByteArray &data)
{
    Message *pB=new REQCMDMessage();
    return pB;
}
