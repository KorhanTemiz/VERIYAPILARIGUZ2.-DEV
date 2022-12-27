/**
* @file Queue.cpp
* @description Kuyruk ile yapilacak islemleri yerine getirir.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 13.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"

Queue::Queue()
{
    front = back = NULL;
    length = 0;
}

int Queue::count() const
{
    return length;
}

bool Queue::isEmpty() const
{
    return length == 0;
}

void Queue::enqueue(const int &item)
{
    Hucre *last = new Hucre(item);
    if (isEmpty())
        front = back = last;
    else
    {
        back->next = last;
        back = back->next;
    }
    length++;
}

void Queue::dequeue()
{
    if (isEmpty())
        throw "Queue is Empty";
        
    Hucre *tmp = front;
    front = front->next;
    delete tmp;
    length--;
}
int Queue::getElement(int index)
{
    Hucre *tmp;
    tmp = this->front;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp->hucre;
}
int Queue::getMax()
{
    Hucre *tmp = front;
    int max = front->hucre;
    while (tmp->next != 0)
    {
        if (tmp->next->hucre > max)
        {
            max = tmp->next->hucre;
        }
        tmp = tmp->next;
    }
    return max;
}

void Queue::CiftBol()
{
    Hucre *tmp;
    tmp = this->front;
    for (int i = 0; i < count(); i++)
    {
        if (tmp->hucre % 2 == 0)
        {
            tmp->hucre = tmp->hucre / 2;
        }
        tmp = tmp->next;
    }
}

Hucre *Queue::getNode(int index)
{

    Hucre *tmp;
    tmp = this->front;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp;
}

int Queue::getMiddleElement()
{
    int ortaIndex = (int)(this->count() / 2);
    getElement(ortaIndex);
}

void Queue::clear()
{
    while (!isEmpty())
        dequeue();
}

Queue::~Queue()
{
    clear();
}
