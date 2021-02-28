/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#ifndef USBCONTROLLER_H
#define USBCONTROLLER_H

#include <iostream>

class USBDeviceObserver {
    void deviceAdded(const std::string &device_id);
    void deviceRemoved(const std::string &device_id);
};

class USBController
{
public:
    USBController();
    void initDevice(const std::string &identifier);

};

#endif // USBCONTROLLER_H
