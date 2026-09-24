#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <stdexcept>
#include <type_traits>
#include <string>

template<typename NODETYPE>
class Tree
{
public:
//constructor
Tree();
//copy constructor
Tree(const TreeNode<NODETYPE> &other);

void insertNode(const NODETYPE &);
void preOrderTraversal()const;
void inOrderTraversal()const;
void postOrderTraversal()const;

//Destructor
~Tree();

private:

TreeNode<NODETYPE> *rootPtr;

TreeNode<NODETYPE>* copyTree(const TreeNode<NODETYPE> *sourceNode);

void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
void preOrderTraversalHelper(TreeNode<NODETYPE> *)const;
void inOrderTraversalHelper(TreeNode<NODETYPE> *)const;
void postOrderTraversalHelper(TreeNode<NODETYPE> *)const;

void clearTree(TreeNode<NODETYPE> *node);

};
#include "Tree.cpp"
#endif

