/**
* @file BSTNode.cpp
* @description Arama Agaci yapisini olusturur.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "BSTNode.hpp"
#include <iostream>

BSTNode::BSTNode(Doku *dt)
{
    this->data = dt;
    this->left = NULL;
    this->right = NULL;
}

