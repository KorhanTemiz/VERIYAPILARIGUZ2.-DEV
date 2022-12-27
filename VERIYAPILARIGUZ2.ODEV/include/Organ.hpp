#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.hpp"
#include "BST.hpp"
#include "Radix.hpp"
class Organ
{

public:
    BST *bst;
    
    Organ();
    bool isMutasyon();
    void mutasyonUygula();

private:
};

#endif