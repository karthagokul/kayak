/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "caninbox.h"
#include <QDebug>


CANInbox::CANInbox()
{

}
void CANInbox::onMessage(const QByteArray& rawdata)
{
    qDebug()<<rawdata;
    //read the control byte and ask message factory to create appropritae message for upper layer.
    Message *m=messagefactory.parseFromBytes (rawdata);
    if(m==0)
    {
        qCritical()<<"Got a message , which can not be identified";
    }
}

