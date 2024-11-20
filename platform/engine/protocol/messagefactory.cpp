/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "messagefactory.h"
#include <QDebug>

MessageFactory::MessageFactory()
{

}

Message* MessageFactory::createReqCMD_initCAN(const QString & canId,const BaudRate& baudRate,const QByteArray &data)
{
    Message::Type t=Message::TxReqCmdConfig;
    Message::Controller ctl=Message::CAN1;
    Message *pB=new Message(t,ctl);
    return pB;
}

Message* MessageFactory::createCANTXMessage(const QString & canId,const BaudRate& baudRate,const QByteArray &data)
{
    Message::Type t=Message::TxCanMessage;
    Message::Controller ctl=Message::CAN1;
    Message *pB=new Message(t,ctl);
    return pB;
}

Message* MessageFactory::parseFromBytes(const QByteArray &data)
{
    Message *m=0;
    //remove  pointers from the message inbox and outbox, will cretae sync issue
    switch(data.at(0))
    {
    case '<':
        //
        break;
    default:
        qWarning()<<"Unable to parse the message from Kayak HW";
        break;
    }
    return m;
}
