/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QByteArray>
#include <QSharedPointer>

class Message :public QObject
{
    enum  Type {
        ReqCmd,
        AckCmd
    };

    enum Direction {
        PlatformToHW,
        HWToPlatform
    };

protected:
    QByteArray header;
    QByteArray data;

public:
    Message();
    ~Message();
    QByteArray getHeader() const
    {
        return header;
    }
    QByteArray rawdata() const
    {
        return header+data;
    }
};

#endif // MESSAGE_H
