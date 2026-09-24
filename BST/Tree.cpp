///////////////////////////////////////////
template<typename NODETYPE>
Tree<NODETYPE>::Tree()
{
this->rootPtr = nullptr;
}
///////////////////////////////////////////
template<typename NODETYPE>
Tree<NODETYPE>::Tree(const TreeNode<NODETYPE> &other)
{
this->rootPtr = copyTree(other.rootPtr);
}
/////////////////////////////////////////////
template<typename NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::copyTree(const TreeNode<NODETYPE> *sourceNode)
{
if(sourceNode == nullptr)
{
return nullptr;
}
TreeNode<NODETYPE> *newNode = new TreeNode<NODETYPE>(sourceNode->data);

    newNode->leftPtr = copyTree(sourceNode->leftPtr);
    newNode->rightPtr = sourceNode->rightPtr ? copyTree(sourceNode->rightPtr) : nullptr;

    return newNode;
}
//////////////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value)
{

    // ── Numeric validation ─────────────────────────────
    if constexpr (std::is_arithmetic<NODETYPE>::value) {
        if (value < 0 || value > 100) {
            throw std::out_of_range("Number must be between 1 and 100.");
        }
    }

    // ── Passed all checks ──────────────────────────────
    insertNodeHelper(&rootPtr, value);
}
////////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> **ptr, const NODETYPE &value)
{


    if (*ptr == nullptr)                          
    {
        *ptr = new TreeNode<NODETYPE>(value);
    }
    else if (value < (*ptr)->data)                
    {
        insertNodeHelper(&((*ptr)->leftPtr), value);
    }
    else if (value > (*ptr)->data)
    {
        insertNodeHelper(&((*ptr)->rightPtr), value);
    }
    else                                          
    {
        cout << value << " is a duplicate value." << endl;
    }
}
////////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal()const
{
preOrderTraversalHelper(rootPtr);
}
/////////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversalHelper(TreeNode<NODETYPE> *ptr)const
{
if(ptr != 0)
{
cout << ptr->data << ' ';
preOrderTraversalHelper(ptr->leftPtr);
preOrderTraversalHelper(ptr->rightPtr);
}
} 
/////////////////////////////////////////////
template <typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversal()const
{
inOrderTraversalHelper(rootPtr);
}
/////////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversalHelper(TreeNode<NODETYPE> *ptr)const
{
if(ptr != 0)
{
inOrderTraversalHelper(ptr->leftPtr);
cout << ptr->data << ' ';
inOrderTraversalHelper(ptr->rightPtr);
}
}
///////////////////////////////////////////
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversal()const
{
postOrderTraversalHelper(rootPtr);
}
/////////////////////////////////////////////
template <typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversalHelper(TreeNode<NODETYPE> *ptr)const
{
if(ptr != 0)
{
postOrderTraversalHelper(ptr->leftPtr);
postOrderTraversalHelper(ptr->rightPtr);
cout << ptr->data << ' ';
}
}
//////////////////////////////////////////
template<typename NODETYPE>
Tree<NODETYPE>::~Tree()
{
clearTree(rootPtr);
}
//////////////////////////////////////////
template<typename NODETYPE>
void Tree<NODETYPE>::clearTree(TreeNode<NODETYPE> *node)
{
if (node != nullptr) {
        clearTree(node->leftPtr);
        clearTree(node->rightPtr);
        delete node;
    }
}
///////////////////////////////////////////
