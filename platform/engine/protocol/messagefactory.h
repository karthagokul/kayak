/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include "message.h"

class MessageFactory
{
public:
    MessageFactory();
    QSharedPointer<Message> createMessage(const QByteArray &inputdata);
};

#endif // MESSAGEFACTORY_H
