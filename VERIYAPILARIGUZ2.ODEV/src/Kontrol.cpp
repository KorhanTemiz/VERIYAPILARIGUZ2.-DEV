/**
* @file Kontrol.cpp
* @description Agacin dengeli olup olmamasini kontrol eder.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "Kontrol.hpp"



bool Kontrol::isbalanced(BST *root){

    return root->isBalanced(root->root);
}