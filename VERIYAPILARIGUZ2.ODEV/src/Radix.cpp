/**
* @file Radix.cpp
* @description Dosyadan okunan sayilari(Doku hucreleri), radix sort algoritmasi ile siralar.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 09.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Radix.hpp"

Radix::Radix()
{
    max = 0;
}

Radix::~Radix() {}

int Radix::getMax(Queue *que)
{
    max = que->getMax();
    return max;
}

void Radix::countSort(Queue *que, int exp)
{
    int output[que->count()];
    int count[10] = {0};

    for (int i = 0; i < que->count(); i++)
        count[(que->getElement(i) / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = (que->count() - 1); i >= 0; i--)
    {
        output[count[(que->getElement(i) / exp) % 10] - 1] = que->getElement(i);
        count[(que->getElement(i) / exp) % 10]--;
    }

    for (int i = 0; i < que->count(); i++)
        que->getNode(i)->hucre = output[i];
}

Queue *Radix::radixsort(Queue *que)
{
    max = getMax(que);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(que, exp);
    }

    return que;
}