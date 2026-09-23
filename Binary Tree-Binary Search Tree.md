# Binary Trees and Binary Search Trees

## What Is a Binary Tree?

A **binary tree** is a tree data structure where each node can have a maximum of two children. These children are referred to as the **left child** and the **right child**.

Unlike a binary search tree, a basic binary tree does not have a specific rule for how values must be organized. Values can be placed in different locations as long as each node has no more than two children.

A binary tree can be understood using the example of a family tree. Each person can represent a node, while the connections between people represent relationships between the nodes. In a binary tree, each node can have at most two children, creating a structure that branches downward from a starting point.

## What Is a Binary Search Tree?

A **binary search tree (BST)** is a special type of binary tree that follows a specific ordering rule.

For every node in a binary search tree:

* Values smaller than the node are placed in the **left subtree**.
* Values greater than the node are placed in the **right subtree**.

For example, if the root contains 50, values smaller than 50 are placed somewhere in the left subtree, while values greater than 50 are placed somewhere in the right subtree.

This organization allows a program to eliminate part of the tree during a search. If the value being searched for is smaller than the current node, the search can continue in the left subtree. If the value is greater, the search can continue in the right subtree.

The easiest way to remember the relationship between the two structures is:

**Every binary search tree is a binary tree, but not every binary tree is a binary search tree.**

A binary tree only requires that each node have at most two children. A binary search tree adds the requirement that the values follow the left-smaller and right-greater ordering rule.

# Important Binary Tree Terminology

Understanding the terminology associated with binary trees is important when working with tree-based data structures.

## Node

A **node** is one of the fundamental components of a binary tree.

A node represents an individual element or piece of information stored in the tree. If the tree stores numbers, a node could contain a value such as 50, 30, or 70.

A node can also contain connections to other nodes. These connections allow the individual nodes to form the overall tree structure.

## Root

The **root** is the starting point and topmost node of the tree.

Every tree begins with a root node. For example, if 50 is the first value inserted into a binary search tree, 50 becomes the root.

The root is important because it is where operations such as searching, inserting, and traversing commonly begin.

## Parent

A **parent** is a node that has one or more children directly connected to it.

For example, if 50 has 30 as its left child and 70 as its right child, then 50 is the parent of both 30 and 70.

A parent can have:

* Only a left child
* Only a right child
* Both a left and right child
* No children

A node with no children is considered a leaf.

## Child

A **child** is a node that is directly connected below another node.

For example, if 50 has 30 and 70 directly below it, then 30 and 70 are children of 50.

The relationship between a parent and child is based on their direct connection within the tree.

## Left Child

A **left child** is the child located on the left side of its parent.

For example, if 50 has 30 as its left child, then 30 is the left child of 50.

In a binary search tree, the left side is used for values that are smaller than the current node.

## Right Child

A **right child** is the child located on the right side of its parent.

For example, if 50 has 70 as its right child, then 70 is the right child of 50.

In a binary search tree, the right side is used for values that are greater than the current node.

## Leaf

A **leaf** is a node that does not have any children.

A leaf has no left child and no right child. Leaves appear at the ends of the branches of a tree.

For example, if 30 has no children, then 30 is a leaf node.

A binary tree can have multiple leaf nodes.

## Subtree

A **subtree** is a smaller tree that exists within a larger tree.

A node and all of the nodes connected below it can be considered a subtree.

For example, if 50 is the root and 30 is its left child, the node 30 and everything connected below 30 make up the left subtree of 50.

Similarly, the node 70 and everything connected below it make up the right subtree of 50.

Subtrees are important because many tree operations work by recursively processing smaller subtrees.

# Predecessor and Successor

The terms **predecessor** and **successor** are especially important when working with the ordered values of a binary search tree.

## Predecessor

The **predecessor** of a value is the value that comes immediately before it when the values in the binary search tree are arranged in sorted order.

For example, if the tree contains the values 20, 30, 40, 50, and 60, the predecessor of 50 is 40.

The predecessor is the largest value that is smaller than the selected value.

## Successor

The **successor** of a value is the value that comes immediately after it when the values are arranged in sorted order.

Using the same values of 20, 30, 40, 50, and 60, the successor of 50 is 60.

The successor is the smallest value that is greater than the selected value.

Predecessors and successors are particularly useful when performing operations such as deleting a node from a binary search tree.

# Basic Node Class

A binary tree or binary search tree is built from individual nodes.

A basic node class normally contains three important members:

* **Data value**
* **Left subtree pointer**
* **Right subtree pointer**

## Data Value

The data value stores the actual information contained inside the node.

For example, if a node represents the number 50, its data member contains 50.

This value is used when performing operations such as searching, inserting, comparing, and traversing the tree.

## Left Subtree Pointer

The left subtree pointer stores the connection to the node's left child or left subtree.

If a left child exists, the pointer references that node.

If there is no left child, the pointer indicates that there is no node connected to the left side.

This pointer allows the tree to branch to the left.

## Right Subtree Pointer

The right subtree pointer stores the connection to the node's right child or right subtree.

If a right child exists, the pointer references that node.

If there is no right child, the pointer indicates that there is no node connected to the right side.

This pointer allows the tree to branch to the right.

Together, the data value and the two pointers provide the basic structure needed to create a binary tree.

The data value stores the information, while the left and right pointers create the relationships between the nodes.

# Binary Search Tree Rule

The defining characteristic of a binary search tree is its ordering rule.

For every node in a binary search tree:

* Values smaller than the node are placed in the left subtree.
* Values greater than the node are placed in the right subtree.

This rule applies throughout the entire tree, not just to the root.

## Example of Insertion

Suppose the first value inserted into the tree is 50. Because it is the first value, 50 becomes the root.

If we insert 30, we compare 30 with 50.

Since 30 is smaller than 50, we move to the left side of 50. If there is no node there, 30 is inserted as the left child of 50.

Next, suppose we insert 70.

We compare 70 with 50. Since 70 is greater than 50, we move to the right side of 50 and insert 70 there.

Now suppose we insert 20.

We first compare 20 with 50. Since 20 is smaller, we move to the left subtree.

We then compare 20 with 30. Since 20 is smaller than 30, we move to the left of 30.

If that position is empty, 20 is inserted there.

The same process occurs when inserting larger values.

Suppose we insert 80.

We first compare 80 with 50. Since 80 is greater, we move to the right subtree.

We then compare 80 with 70. Since 80 is greater than 70, we move to the right of 70.

If that position is empty, 80 is inserted there.

This comparison process continues until the correct empty position is found.

# Searching a Binary Search Tree

The ordering rule of a binary search tree makes searching more efficient than searching through an unordered binary tree.

Suppose we are searching for the value 80.

We begin at the root, which contains 50.

Since 80 is greater than 50, we know that 80 must be located in the right subtree if it exists there. There is no need to search the left subtree.

We then compare 80 with the next node.

If the current node contains 70, 80 is greater than 70, so we continue to the right.

If we eventually reach a node containing 80, the value has been found.

If we reach an empty position before finding 80, then the value does not exist in the tree.

The important idea is that each comparison helps determine which direction the search should take.

* If the target is **smaller**, move left.
* If the target is **greater**, move right.
* If the target **matches**, the value has been found.

# Duplicate Values

A binary search tree must also have a defined rule for handling duplicate values.

In this implementation, **duplicate values are ignored**.

For example, if the tree already contains 50 and another 50 is inserted, the tree does not create another node.

Instead, the duplicate value is ignored and the original 50 remains in the tree.

This means that each value appears only once in the binary search tree.

Having a defined duplicate-value rule is important because it ensures that the insertion process behaves consistently.

# Binary Tree vs. Binary Search Tree

| Feature                   | Binary Tree                      | Binary Search Tree                   |
| ------------------------- | -------------------------------- | ------------------------------------ |
| Maximum children per node | 2                                | 2                                    |
| Left child                | Possible                         | Contains smaller values              |
| Right child               | Possible                         | Contains greater values              |
| Value ordering            | No required ordering             | Ordered                              |
| Searching                 | May require examining many nodes | Can eliminate subtrees during search |
| Duplicate handling        | Depends on implementation        | Defined by implementation            |

The main difference is **organization**.

A binary tree limits each node to a maximum of two children but does not require the values to follow a particular order.

A binary search tree follows the same two-child limitation but also organizes values so that smaller values belong in the left subtree and greater values belong in the right subtree.

# Summary

A **binary tree** is a tree data structure where each node can have at most two children. These children are referred to as the left child and right child.

A **binary search tree** is a specialized binary tree that organizes values according to a specific ordering rule. Values smaller than a node are placed in its left subtree, while values greater than the node are placed in its right subtree.

Important binary tree terminology includes **node, root, parent, child, left child, right child, leaf, subtree, predecessor, and successor**.

A basic node contains a data value along with pointers to its left and right subtrees. These components allow individual nodes to be connected together to form the tree.

The binary search tree ordering rule makes searching more efficient because each comparison determines whether the search should continue to the left or right.

In this implementation, duplicate values are ignored, meaning that the tree stores each value only once.

The key concept to remember is that **a binary tree describes the structure, while a binary search tree adds an ordering rule to that structure**.
