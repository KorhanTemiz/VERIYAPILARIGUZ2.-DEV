#ifndef Queue_hpp
#define Queue_hpp
#include "Hucre.hpp"

class Queue
{
public:
    Queue();
    int count() const;
    bool isEmpty() const;
    void enqueue(const int &item);
    void dequeue();
    void clear();
    ~Queue();
    int getElement(int index);
    int getMiddleElement();
    int getMax();
    Hucre *getNode(int index);
    void CiftBol();

private:
    Hucre *front;
    Hucre *back;
    int length;
};

#endif