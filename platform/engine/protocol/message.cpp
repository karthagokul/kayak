/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
 *******************************************************************
*/
#include "message.h"
#include <QDebug>

Message::Message(const Type &t,const Controller & ctr)
{
    type=t;
    ctrller= ctr;
}

Message::~Message()
{
    qDebug()<<"destructing message";
}
