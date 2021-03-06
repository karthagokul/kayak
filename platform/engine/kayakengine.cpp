/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/

#include "kayakengine.h"
#include "logger.h"


structlog GologgerConfiguration = {};


void setKayakLogLevel(const typelog & log_level)
{
    GologgerConfiguration.level = log_level;
}

KayakEngine::KayakEngine()
{
    GologgerConfiguration.headers = true;
    GologgerConfiguration.level = ALL_LOG_LEVEL;

    LOG_FUNCTION_NAME;
    LOG(DEBUG) << "Hello Debug!";
    LOG(WARN) << "Hello Warning!";
    LOG(INFO) << "Hello Info!";
    LOG(ERROR) << "Hello Error!";
}

KayakEngine::~KayakEngine()
{

}
