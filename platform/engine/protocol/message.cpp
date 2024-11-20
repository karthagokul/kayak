/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
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
