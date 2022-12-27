#ifndef BSTNode_hpp
#define BSTNode_hpp
#include "Doku.hpp"
class BSTNode
{
public:
    Doku *data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(Doku *dt);

private:
};

#endif