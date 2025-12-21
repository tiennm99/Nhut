#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

class Queue
{
  private:
    List *queue;

  public:
    Queue();
    void enQueue(int);
    int deQueue();
    ~Queue();
};

#endif // QUEUE_H