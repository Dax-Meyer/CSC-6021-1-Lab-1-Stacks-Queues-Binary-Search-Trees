# Stacks

## What Is a Stack?

A **stack** is a linear data structure that stores and organizes elements according to the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first element removed.

A common real-world example of a stack is a pile of books. Imagine placing a math book on a desk, followed by a science book, and then an English book. The English book is now at the top of the pile. If you want to remove a book without moving the others, you must remove the English book first.

The English book was the last book added, so it is the first book removed. This demonstrates the LIFO principle.

It is important to distinguish a stack from a queue. A stack follows **LIFO**, while a queue follows **FIFO (First In, First Out)**. A line at a store is an example of FIFO because the person who enters the line first is normally the first person served.

## Top of the Stack

A stack has one primary position called the **top**.

The top represents the location where elements are both added and removed. Unlike a queue, which adds elements at the rear and removes them from the front, a stack performs its main operations at the same end.

For example, if a stack contains the values 10, 20, and 30, then 30 is the top element. If another value, 40, is added, 40 becomes the new top.

If 40 is removed, 30 becomes the top again.

This behavior is what allows the stack to follow the LIFO principle.

## Common Stack Operations

Stacks commonly use several operations to manage their elements.

### push()

The **push()** operation adds a new element to the top of the stack.

For example, if a stack contains 10, 20, and 30, performing push(40) adds 40 to the top of the stack.

The newly added element becomes the new top element.

### pop()

The **pop()** operation removes the element from the top of the stack.

For example, if a stack contains 10, 20, 30, and 40, performing pop() removes 40.

The next element, 30, then becomes the top of the stack.

### peek() or top()

The **peek()** or **top()** operation allows the program to view the element currently at the top without removing it.

For example, if 40 is the top element, peek() can be used to identify 40 while leaving it in the stack.

This is useful when a program needs to inspect the next element that would be removed.

### isEmpty()

The **isEmpty()** operation determines whether the stack contains any elements.

If the stack contains no elements, isEmpty() returns true.

This operation is useful before performing pop() because attempting to remove an element from an empty stack can cause an underflow condition.

### isFull()

The **isFull()** operation determines whether an array-based stack has reached its maximum capacity.

For example, if an array-based stack has a capacity of five and currently contains five elements, the stack is full.

This operation can be used before performing push() to prevent an overflow condition.

### displayAll()

The **displayAll()** operation displays all of the elements currently stored in the stack.

For example, if a stack contains 10, 20, 30, and 40, displayAll() would show those elements in their current stack order.

## Stack Overflow and Underflow

Two important conditions that must be handled when implementing a stack are **overflow** and **underflow**.

### Stack Overflow

**Stack overflow** occurs when an attempt is made to add an element to a stack that has already reached its maximum capacity.

For example, imagine a shelf that can hold five books. If five books are already on the shelf and another book is added, there is no available space.

In an array-based stack, attempting to perform push() when the stack is already full can cause stack overflow.

The isFull() operation can be used to check whether the stack has available capacity before performing push().

### Stack Underflow

**Stack underflow** occurs when an attempt is made to remove an element from an empty stack.

For example, if there are no books in a pile and someone attempts to remove a book, there is nothing available to remove.

In a stack, attempting to perform pop() when the stack is empty can cause stack underflow.

The isEmpty() operation can be used to check whether an element is available before performing pop().

# Array-Based Stack

An **array-based stack** is a stack that uses an array to store its elements.

An array can be viewed as a collection of positions that can each hold an element. For example, an array-based stack with a capacity of five can store up to five elements.

A variable called **top** is commonly used to keep track of the current top position of the stack.

When an element is pushed onto the stack, the top position is updated to the newly added element.

When an element is popped, the top position moves back to the previous element.

This allows the program to keep track of which element should be accessed or removed next.

## Advantages of an Array-Based Stack

Array-based stacks provide several advantages.

### Simple Implementation

Array-based stacks are relatively straightforward to implement because the elements are stored in a contiguous section of memory and the stack only needs to keep track of the top position.

### Fast Operations

Common stack operations such as push(), pop(), and peek() can generally be performed in **O(1) time**.

This means that these operations take constant time regardless of how many elements are currently stored in the stack.

### Efficient Memory Organization

Because the elements are stored in an array, they are organized in a contiguous section of memory.

An array-based stack also does not require additional pointer information for each element, which can make it simpler than a linked-list implementation.

# Limitations of an Array-Based Stack

Although array-based stacks are simple and efficient, they also have limitations.

### Fixed Capacity

One of the main limitations of a traditional array-based stack is its fixed capacity.

For example, if a stack has a capacity of five, it can only store five elements at a time.

Once all five positions are occupied, another element cannot be added unless the stack provides a way to increase its capacity.

### Unused Space

An array-based stack may have allocated space that is not currently being used.

For example, a stack may have a capacity of 100 but currently contain only five elements. The remaining positions are allocated but are not currently storing stack elements.

This can result in unused memory, particularly when a large capacity is allocated but the stack usually contains only a small number of elements.

### Resizing Overhead

A dynamic array-based stack can be designed to increase its capacity when additional space is needed.

When the existing array becomes full, the program may need to create a larger array and copy the existing elements into it.

Although this allows the stack to grow, resizing requires additional processing and memory during the operation.

# Stack vs. Queue

Stacks and queues are both linear data structures, but they organize the removal of elements differently.

| Feature            | Stack           | Queue           |
| ------------------ | --------------- | --------------- |
| Ordering principle | LIFO            | FIFO            |
| Add operation      | push()          | enqueue()       |
| Remove operation   | pop()           | dequeue()       |
| Primary position   | Top             | Front and Rear  |
| View next element  | peek() or top() | Front           |
| Common example     | Pile of books   | Line at a store |

The main difference is the order in which elements are removed.

A stack removes the **most recently added element first**, while a queue removes the **oldest element first**.

# Applications of Stacks

Stacks are useful in many computing applications where the most recently added item needs to be processed first.

Examples include:

* **Function calls:** Programming languages use a call stack to keep track of active function calls and their execution order.
* **Undo operations:** Applications can use stacks to keep track of previous actions so the most recent action can be undone first.
* **Expression evaluation:** Stacks can be used when evaluating mathematical expressions and processing operators and operands.
* **Parentheses matching:** Compilers and other programs can use stacks to determine whether opening and closing parentheses are properly matched.
* **Depth-first search:** Stacks can be used to implement depth-first search when traversing graphs and trees.
* **Backtracking:** Algorithms can use stacks to keep track of previous states when exploring different possible solutions.

# Summary

A stack is a **LIFO (Last In, First Out)** linear data structure where elements are added and removed from the top.

The primary stack operations are **push(), pop(), peek() or top(), isEmpty(), isFull(), and displayAll()**.

The push() operation adds an element to the top, while pop() removes the element from the top. The peek() or top() operation allows the program to view the top element without removing it. The isEmpty() operation checks whether the stack contains any elements, while isFull() determines whether an array-based stack has reached its capacity. The displayAll() operation shows the elements currently stored in the stack.

**Stack overflow** occurs when an attempt is made to add an element to a full stack, while **stack underflow** occurs when an attempt is made to remove an element from an empty stack.

An array-based stack is relatively simple and provides efficient operations, with push(), pop(), and peek() generally operating in **O(1) time**. However, a traditional array-based stack has a fixed capacity, and unused allocated space can be inefficient.

The key concept to remember is that a stack follows **LIFO**: the **last element added is the first element removed**.
