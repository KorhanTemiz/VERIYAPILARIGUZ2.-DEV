#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"
#include <iostream>
using namespace std;

class Radix{

public:
    Radix();

    Queue *radixsort(Queue *); 
    ~Radix();

private:
    int max;
    int getMax(Queue *que);
    void countSort(Queue *que, int exp);

};





#endif