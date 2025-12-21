#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
    List *myList1 = new List,
         *myList2 = new List;
    myList1->addFirst(1);
    myList1->addFirst(0);
    myList1->addFirst(1);
    myList1->addFirst(0);
    myList1->addFirst(5);
    myList1->display();
    myList2->addFirst(1);
    myList2->addFirst(2);
    myList2->addFirst(3);
    myList2->display();
    myList1->displayPoly();
    myList2->displayPoly();
    List *result = addPoly(myList1, myList2);
    myList1->display();
    myList2->display();
    if (result != NULL)
        result->display();
    myList1->display();
    myList2->display();
    myList1->displayPoly();
    myList2->displayPoly();
    result->displayPoly();
    cout << myList1->returnFirst() << endl;
    myList1->removeFirst();
    myList1->display();
    cout << myList1->returnLast() << endl;
    myList1->removeLast();
    myList1->display();
    return 0;
}