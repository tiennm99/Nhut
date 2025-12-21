#include "Stack.h"

Stack::Stack()
{
    stack = new List;
}

void Stack::push(int newdata)
{
    stack->addFirst(newdata);
}

int Stack::pop()
{
    int ret = stack->returnFirst();
    stack->removeFirst();
    return ret;
}

Stack::~Stack()
{
    delete stack;
}