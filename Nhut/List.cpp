#include "List.h"
#include "Queue.h"
#include "Stack.h"

List::List()
{
    pHead = NULL;
    count = 0;
}

void List::addLast(int newdata)
{
    Node *pNew = new Node;
    pNew->data = newdata;
    if (pHead == NULL)
    {
        pHead = pNew;
        ++count;
        return;
    }
    Node *pTemp = pHead;
    while (pTemp->next != NULL)
    {
        pTemp = pTemp->next;
    }
    pTemp->next = pNew;
    ++count;
}

void List::addConstant(int nConstant)
{
    Node *pTemp = pHead;
    if (pTemp == NULL)
        return;
    while (pTemp->next != NULL)
        pTemp = pTemp->next;
    pTemp->data += nConstant;
    return;
}

void List::addFirst(int newdata)
{
    Node *pTemp = new Node;
    pTemp->data = newdata;
    pTemp->next = pHead;
    pHead = pTemp;
    count++;
}

void List::display()
{
    Node *pTemp = pHead;
    while (pTemp != NULL)
    {
        cout << pTemp->data << " ";
        pTemp = pTemp->next;
    }
    cout << endl;
}

void List::displayPoly()
{
    Node *pTemp = pHead;
    int i = 0;
    while (pTemp != NULL)
    {
        int index = count - 1 - i;
        if (pTemp->data != 0)
        {
            if (pTemp->data > 0)
            {
                if (i != 0)
                    cout << "+";
            }
            cout << pTemp->data;
            if (index == 1)
                cout << "x";
            else if (index > 1)
                cout << "x^" << index;
        }
        ++i;
        pTemp = pTemp->next;
    }
    cout << endl;
}

void List::removeFirst()
{
    if (pHead == NULL)
        return;
    Node *pDel = pHead;
    pHead = pHead->next;
    delete pDel;
    --count;
}

void List::removeLast()
{
    if (pHead == NULL)
        return;
    Node *pTemp = pHead;
    if (count == 1)
    {
        pHead = NULL;
        delete pTemp;
        count = 0;
        return;
    }
    Node *pPrev = NULL;
    while (pTemp->next != NULL)
    {
        pPrev = pTemp;
        pTemp = pTemp->next;
    }
    pPrev->next = NULL;
    delete pTemp;
    --count;
}

int List::returnFirst()
{
    if (pHead == NULL)
        return 0;
    return pHead->data;
}

int List::returnLast()
{
    if (pHead == NULL)
        return 0;
    Node *pTemp = pHead;
    while (pTemp->next != NULL)
        pTemp = pTemp->next;
    return pTemp->data;
}

List::~List()
{
    Node *pTemp = pHead;
    while (pTemp != NULL)
    {
        pTemp = pTemp->next;
        delete pHead;
        pHead = pTemp;
    }
}

List *addPoly(List *list1, List *list2)
{
    if (list1 == NULL || list2 == NULL)
        return NULL;
    int i = list1->count,
        j = list2->count;
    Node *pHead1 = list1->pHead;
    Node *pHead2 = list2->pHead;
    if (i <= 0 || j <= 0)
        return NULL;
    if (i > j)
    {
        while (i > j)
        {
            pHead1 = pHead1->next;
            --i;
        }
    }
    else
    {
        while (j > i)
        {
            pHead2 = pHead2->next;
            --j;
        }
    }
    List *ret = new List;
    while (i > 0)
    {
        int t = pHead1->data + pHead2->data;
        ret->addLast(t);
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
        --i;
    }
    return ret;
}

List *reverseListWithStack(List *list)
{
    if (list == NULL)
        return NULL;
    Node *pTemp = list->pHead;
    Stack *stack = new Stack;
    int count = 0;
    while (pTemp != NULL)
    {
        stack->push(pTemp->data);
        pTemp = pTemp->next;
        ++count;
    }
    List *ret = new List;
    while (count > 0)
    {
        ret->addLast(stack->pop());
        --count;
    }
    return ret;
}

List *reverseListWithQueue(List *list)
{
    if (list == NULL)
        return NULL;
    Node *pTemp = list->pHead;
    Queue *queue = new Queue;
    int count = 0;
    while (pTemp != NULL)
    {
        queue->enQueue(pTemp->data);
        pTemp = pTemp->next;
        ++count;
    }
    List *ret = new List;
    while (count > 0)
    {
        ret->addFirst(queue->deQueue());
        --count;
    }
    return ret;
}

List *appendList(List *list1, List *list2)
{
    List *ret;
    if (list2 == NULL)
    {
        ret = list1;
    }
    else if (list1 == NULL)
    {
        ret = list2;
    }
    else
    {
        Node *pTemp;
        ret = new List;
        pTemp = list1->pHead;
        while (pTemp != NULL)
        {
            ret->addLast(pTemp->data);
            pTemp = pTemp->next;
            list1->removeFirst();
        }
        pTemp = list2->pHead;
        while (pTemp != NULL)
        {
            ret->addLast(pTemp->data);
            pTemp = pTemp->next;
            list2->removeFirst();
        }
    }
    delete list1;
    list1 = NULL;
    delete list2;
    list2 = NULL;
    return ret;
}
