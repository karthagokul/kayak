/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef ACKCMDMESSAGE_H
#define ACKCMDMESSAGE_H

#include "message.h"

class ACKCMDMessage:public Message
{
public:
    ACKCMDMessage();
};

#endif // ACKCMDMESSAGE_H