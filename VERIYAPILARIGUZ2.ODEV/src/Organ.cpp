/**
* @file Organ.cpp
* @description Dokularda mutasyon var mi yok mu kontrol eder ve buna gore mutasyonu uygular.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Organ.hpp"

Organ::Organ()
{
    bst = new BST();
}
bool Organ::isMutasyon()
{
    return bst->isMutasyon(bst->root);
}

void Organ::mutasyonUygula()
{

    if (bst->root->data->getMiddle() % 50 == 0)
    {
        bst->AgaciYarila(bst->root);
        BST *tmp = new BST();
        bst->postOrderAdd(bst->root, tmp);
        delete bst;
        bst = tmp;
    }
}