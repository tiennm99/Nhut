#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class List
{
private:
  int count;
  Node *pHead;

public:
  List();
  void addLast(int);
  void addConstant(int);
  void addFirst(int);
  void removeFirst();
  void removeLast();
  int returnFirst();
  int returnLast();
  void display();
  void displayPoly();
  friend List *addPoly(List *, List *);
  friend List *reverseListWithStack(List *);
  friend List *reverseListWithQueue(List *);
  friend List *appendList(List *, List *);
  ~List();
};

#endif // LIST_H