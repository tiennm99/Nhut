#include "Queue.h"

Queue::Queue()
{
    queue = new List;
}

void Queue::enQueue(int newdata)
{
    queue->addLast(newdata);
}

int Queue::deQueue()
{
    int ret = queue->returnFirst();
    queue->removeFirst();
    return ret;
}

Queue::~Queue()
{
    delete queue;
}