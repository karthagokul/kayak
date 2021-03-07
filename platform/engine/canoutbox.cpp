/*
 *******************************************************************
 * Copyright (C) 2021-2022 Bolgatty BV
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Bolgatty BV
 *******************************************************************
*/
#include "canoutbox.h"
#include <QDebug>

CANOutbox::CANOutbox()
{

}

void CANOutbox::run()
{
    while (!message_queue.isEmpty())
    {
        Message *m=message_queue.dequeue();
        qDebug()<<m->rawdata ()<<" [Sending]";
        //now send it to serial device
    }
}


void CANOutbox::post(Message *message)
{
    //lock the queue
    resource.lock();
    message_queue.enqueue(message);
    resource.unlock();
    //start processing
    start();
}
