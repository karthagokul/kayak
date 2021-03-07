/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "router.h"
#include "message.h"

Message* Protocol::construct(const QByteArray &raw)
{
    QChar cti=raw.at(0);
    if((cti=='!')||(cti=='#')||(cti=='@')||(cti=='$'))
    {

    }
    //something like this, we shall check the bytes and create a message
}

Router::Router()
{

}
