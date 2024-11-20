/*
 *******************************************************************
 * Copyright (C) 2021-2022 Gokul Kartha
 * This file is part of Kayak.
 * Kayak can not be copied and/or distributed without the express
 * permission of Gokul Kartha
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
        qDebug()<<" [Sending] "<<m->rawdata ();
        //now send it to serial device

        //Lets freeup memeory
        m->deleteLater ();
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
