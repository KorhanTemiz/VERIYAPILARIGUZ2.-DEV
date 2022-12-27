/**
* @file Bst.cpp
* @description Ikili arama agaci ile ilgili islemleri yapar.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 11.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "BST.hpp"

void BST::SearchAndAdd(BSTNode *&subNode, Doku *newItem)
{
    if (subNode == NULL)
    {
        subNode = new BSTNode(newItem);
    }
    else if (newItem->getMiddle() < subNode->data->getMiddle())
    {
        SearchAndAdd(subNode->left, newItem);
    }
    else if (newItem->getMiddle() > subNode->data->getMiddle())
    {
        SearchAndAdd(subNode->right, newItem);
    }
    else if (newItem->getMiddle() == subNode->data->getMiddle())
    {
        SearchAndAdd(subNode->left, newItem);
    }
    else
        return;
}
bool BST::SearchAndDelete(BSTNode *subNode, Doku *data)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == data)
        return DeleteNode(subNode);
    else if (data->getMiddle() < subNode->data->getMiddle())
        return SearchAndDelete(subNode->left, data);
    else
        return SearchAndDelete(subNode->right, data);
}
bool BST::DeleteNode(BSTNode *subNode)
{
    BSTNode *DelNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        DelNode = subNode->left;
        BSTNode *parent = subNode;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->data = DelNode->data;
        if (parent == subNode)
            subNode->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
void BST::postorder(BSTNode *subNode)
{
    if (subNode != NULL)
    {
        postorder(subNode->left);
        postorder(subNode->right);
        cout << subNode->data->getMiddle() << " ";
    }
}
bool BST::isMutasyon(BSTNode *root)
{
    if (root != NULL)
    {
        /* if (root->data->getMiddle() % 50 == 0)
         {

             return 1;

         }else{
             if(isMutasyon(root->left)||isMutasyon(root->right))
                 return 1;

         }*/

        if (root->data->getMiddle() % 50 == 0)
        {

            return 1;
        }

        return 0;
    }
}
void BST::postOrderAdd(BSTNode *root, BST *bst)
{
    if (root != NULL)
    {    
        postOrderAdd(root->left, bst);
        postOrderAdd(root->right, bst);
        bst->Add(root->data);
    }
}
void BST::AgaciYarila(BSTNode *root)
{

    if (root != NULL)
    {   
        AgaciYarila(root->left);
        AgaciYarila(root->right);
        root->data->CiftOlanlariYarila();
        Radix radix;
        radix.radixsort(root->data->queue);
    }
}
int BST::Height(BSTNode *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}
void BST::PrintLevel(BSTNode *subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->data << " ";
    else
    {
        PrintLevel(subNode->left, level - 1);
        PrintLevel(subNode->right, level - 1);
    }
}
bool BST::Search(BSTNode *subNode, Doku *item)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == item)
        return true;
    if (item < subNode->data)
        return Search(subNode->left, item);
    else
        return Search(subNode->right, item);
}

BST::BST()
{
    root = NULL;
}
bool BST::isEmpty() const
{
    return root == NULL;
}
void BST::Add(Doku *newItem)
{
    SearchAndAdd(root, newItem);
}
void BST::Delete(Doku *data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}
void BST::postorder()
{
    postorder(root);
}
int BST::Height()
{
    return Height(root);
}
bool BST::Search(Doku *item)
{
    return Search(root, item);
}
void BST::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}

bool BST::isBalanced(BSTNode *root)
{
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = Height(root->left);
    rh = Height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}