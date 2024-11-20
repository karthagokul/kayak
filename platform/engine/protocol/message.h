/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QByteArray>
#include <QSharedPointer>

class Message :public QObject
{
public:
    enum  Type {
        TxReqCmdConfig,
        TxCanMessage,
        RxCanMessage,
        RxAckCmd
    };

    enum Controller {
        CAN1,
        CAN2
    };


protected:
    QByteArray data;
    Type type;
    Controller ctrller;

public:
    Message(const Type &type,const Controller &controller);
    ~Message();

    void setRawData(const QByteArray &d)
    {
        data=d;
    }
    QByteArray rawdata() const
    {
        return data;
    }
};

#endif // MESSAGE_H
