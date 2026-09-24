#ifndef TREENODE_H
#define TREENODE_H

//foward declaration of class Tree
template<typename NODETYPE> class Tree;

template<typename NODETYPE>
class TreeNode
{
//Declaring class Tree as a friend of TreeNode
friend class Tree<NODETYPE>;
public:

TreeNode(const NODETYPE &value);

NODETYPE getData() const;

private:
TreeNode<NODETYPE> *leftPtr;
NODETYPE data;
TreeNode<NODETYPE> *rightPtr;
};
#include "Node.cpp"
#endif


