/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/

#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
    enum LogLevel {
        Info,
        Debug,
        Warning,
        Error
    };

public:
    Engine();
    void setLogLevel(const LogLevel &loglevel);
    ~Engine();
};


#endif // ENGINE_H
