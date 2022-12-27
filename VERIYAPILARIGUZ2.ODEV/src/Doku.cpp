/**
* @file Doku.cpp
* @description Doku hucrelerini tutar,Orta eleman bilgisini dondurur, doku hucrelerini mutasyon durumunda yarilar.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Doku.hpp"

Doku::Doku(Queue *items)
{

    this->queue = items;
}
int Doku::getMiddle()
{
    return this->queue->getMiddleElement();
}
void Doku::CiftOlanlariYarila()
{   
    this->queue->CiftBol();
}