#ifndef STACK_H
#define STACK_H

#include "List.h"

class Stack
{
private:
  List *stack;

public:
  Stack();
  void push(int);
  int pop();
  ~Stack();
};

#endif // STACK_H