/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef MESSAGEROUTER_H
#define MESSAGEROUTER_H

#include <QThread>
#include <QQueue>
#include <QByteArray>

class Message;

class Protocol
{
public:
    Message* construct(const QByteArray &raw);
};

class Router:public QThread
{
private:
    QQueue<QByteArray> readQueue;
    QQueue<QByteArray> writeQueue;
public:
    Router();
};

#endif // MESSAGEROUTER_H
