/**
* @file Hucre.cpp
* @description Kuyruk yapisini olusturmada ve hucre bilgisini tutmada kullanilir.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Hucre.hpp"

Hucre::Hucre(int data,Hucre *next)
{
    this->hucre = data;
    this->next = next;
}