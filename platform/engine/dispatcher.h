/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QThread>

class Dispatcher :public QThread
{
public:
    Dispatcher();
    void push(const QByteArray &data);

protected:
    void run();


};

#endif // DISPATCHER_H
