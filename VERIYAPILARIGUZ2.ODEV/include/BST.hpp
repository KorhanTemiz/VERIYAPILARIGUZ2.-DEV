#ifndef BST_hpp
#define BST_hpp
#include "BSTNode.hpp"
#include "stdio.h"
#include "Radix.hpp"
using namespace std;
class BST
{

public:
    BST();
    bool isEmpty() const;
    void Add( Doku *newItem);
    void Delete(Doku *data);
    void postorder();
    int Height();
    bool Search(Doku *item);
    void Clear();
    bool isMutasyon(BSTNode *root);
    bool isBalanced(BSTNode *root);
    void postOrderAdd(BSTNode *root,BST *bst);
    void AgaciYarila(BSTNode *root);
BSTNode *root;
private:
    

    void SearchAndAdd(BSTNode *&subNode,Doku *newItem);
    bool SearchAndDelete(BSTNode *subNode, Doku *data);
    bool DeleteNode(BSTNode *subNode);
    void postorder(BSTNode *subNode);
    int Height(BSTNode *subNode);
    void PrintLevel(BSTNode *subNode, int level);
    bool Search(BSTNode *subNode, Doku *item);
};

#endif