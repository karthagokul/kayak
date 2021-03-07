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


class Message
{
    enum  Type {
        ReqCmd,
        AckCmd
    };

    enum Direction {
        PlatformToHW,
        HWToPlatform
    };

public:
    Message();

};

#endif // MESSAGE_H
