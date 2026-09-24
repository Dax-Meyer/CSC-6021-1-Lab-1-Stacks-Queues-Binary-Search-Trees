
/////////////////////////////////////////
template<typename NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &value)
: leftPtr(nullptr),
data(value),
rightPtr(nullptr)
{}
//////////////////////////////////////////
template<typename NODETYPE>
NODETYPE TreeNode<NODETYPE>::getData()const
{
return data;
}
//////////////////////////////////////////
