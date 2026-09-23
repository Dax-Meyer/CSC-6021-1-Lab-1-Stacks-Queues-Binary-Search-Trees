# Queues and Circular Queues

## What Is a Queue?

A **queue** is a linear data structure that stores and organizes elements according to the **FIFO (First In, First Out)** principle. This means that the first element added to the queue is the first element removed.

A common real-world example is a line at a checkout counter. The first customer to enter the line is normally the first customer served, while new customers join at the back of the line. A queue works in the same way: elements enter from one end and leave from the other.

Another example is cars waiting at a toll booth. The first car to arrive is the first car to pass through, while cars arriving afterward wait behind it.

## Front and Rear

A queue has two important positions:

* **Front** – The position where elements are removed.
* **Rear** – The position where new elements are added.

For example, if a queue contains the values 10, 20, 30, 40, and 50, the front is 10 and the rear is 50. If 10 is removed, 20 becomes the next element at the front. If 60 is added, it is placed at the rear.

This demonstrates the FIFO principle because 10 was added before the other elements and was therefore removed first.

## Common Queue Operations

Queues commonly use several operations to manage their elements.

### enqueue()

The enqueue() operation adds a new element to the **rear** of the queue.

For example, if a queue contains 10, 20, and 30, performing enqueue(40) adds 40 to the rear. The queue now contains 10, 20, 30, and 40.

### dequeue()

The dequeue() operation removes an element from the **front** of the queue.

For example, if a queue contains 10, 20, 30, and 40, performing dequeue() removes 10. The queue now contains 20, 30, and 40.

### isEmpty()

The isEmpty() operation determines whether the queue currently contains any elements.

If the queue contains no elements, isEmpty() returns true.

### isFull()

The isFull() operation determines whether an array-based queue has reached its maximum capacity.

For example, if a queue has a capacity of five and currently contains five elements, the queue is full.

### displayAll()

The displayAll() operation displays all of the elements currently stored in the queue.

For example, if the queue contains 10, 20, 30, and 40, displayAll() would display those elements in their current queue order.

## Queue Overflow and Underflow

Two important conditions that must be handled when implementing a queue are **overflow** and **underflow**.

### Queue Overflow

**Queue overflow** occurs when an attempt is made to add an element to a queue that is already full.

For example, if an array-based queue has a capacity of five and all five positions are currently occupied, attempting to add another element results in queue overflow.

The isFull() operation can be used to check for this condition before performing an enqueue() operation.

### Queue Underflow

**Queue underflow** occurs when an attempt is made to remove an element from an empty queue.

For example, if the queue contains no elements and a dequeue() operation is attempted, there is no element available to remove.

The isEmpty() operation can be used to check for this condition before performing a dequeue() operation.

# Linear Array Queue

A **linear array queue** uses an array to store the elements of the queue. Although this approach is straightforward, it has an important limitation: **unused positions at the beginning of the array may become inaccessible**.

For example, imagine an array with five positions containing five elements. The front is at the first position and the rear is at the last position.

If the first two elements are removed, the first two positions become empty. However, the rear is still near the end of the array.

As new elements are added, the rear continues moving toward the end of the array. Once the rear reaches the final position, the queue may be considered full even though there are empty positions at the beginning.

This creates inefficient use of the available array space.

The problem occurs because a basic linear queue moves in one direction. It does not automatically wrap around to reuse the positions that became empty after elements were removed.

## The Problem With a Linear Queue

The main limitation of a linear array queue is that it can appear to be full even when unused positions exist at the beginning of the array.

For example, suppose an array has five positions and currently contains three elements because two elements were previously removed from the front. The two empty positions at the beginning cannot easily be reused by a basic linear queue without additional operations.

One possible solution would be to shift all remaining elements toward the beginning of the array. However, repeatedly shifting elements can be inefficient.

A **circular queue** provides a more efficient solution.

# Circular Queue

A **circular queue** is a queue that treats the array as though the last position is connected back to the first position.

Instead of stopping when the rear reaches the last index, the rear can wrap around to the beginning of the array if space is available.

For example, if an array has five positions numbered 0 through 4, the indexes normally progress from 0 to 1, then 2, 3, and 4.

In a circular queue, after index 4, the next position is index 0.

This creates a continuous circular structure within the array.

## How a Circular Queue Reuses Space

Suppose an array contains five positions and the first two elements have been removed. The first two positions are now empty while the remaining elements occupy the later positions.

In a linear queue, these empty positions may not be reusable.

In a circular queue, when the rear reaches the final position, it can wrap around to index 0 and place a new element there.

The next new element can then be placed at index 1.

This allows the circular queue to reuse the positions that were previously occupied by elements that had already been removed.

## Wrap-Around Behavior

The most important feature of a circular queue is its **wrap-around behavior**.

The indexes move forward through the array until the final position is reached. After the final position, the next position is the first position.

For an array with five positions, the sequence would be:

0, 1, 2, 3, 4, 0, 1, 2, and so on.

This allows the queue to continuously reuse available positions without shifting the existing elements.

In C++, this behavior is commonly implemented using the modulo operator.

The rear can be updated using the formula:

rear = (rear + 1) % CAPACITY

If the rear is at index 3 in an array with a capacity of 5, the next position is index 4.

If the rear is at index 4, the calculation wraps the rear back to index 0.

This is what allows the array to behave like a circle.

# Linear Queue vs. Circular Queue

| Feature                | Linear Queue       | Circular Queue |
| ---------------------- | ------------------ | -------------- |
| Data structure         | Array-based        | Array-based    |
| FIFO principle         | Yes                | Yes            |
| Uses front and rear    | Yes                | Yes            |
| Wraps around           | No                 | Yes            |
| Reuses empty positions | Limited            | Yes            |
| Memory utilization     | Can be inefficient | More efficient |
| Implementation         | Simpler            | More complex   |

The primary difference between the two structures is how they use the available space in the array.

A linear queue moves toward the end of the array and can leave unused positions at the beginning.

A circular queue allows the rear to wrap around to the beginning of the array and reuse those available positions.

# Advantages of a Circular Queue

Circular queues provide several important advantages.

### Efficient Memory Usage

A circular queue can reuse positions that become available after elements are removed from the front.

### No Unnecessary Shifting

Elements do not need to be shifted toward the beginning of the array to make room for new elements.

### Efficient Insertions and Removals

With properly maintained front and rear positions, enqueue() and dequeue() operations can be performed efficiently.

### Useful for Repeating Processes

Circular queues are useful in situations where data is continuously added and removed.

Examples include:

* Task scheduling
* Request processing
* Network buffering
* Operating system processes
* Streaming data
* Resource management

# Challenges of Circular Queues

Although circular queues use array space more efficiently, they are more complicated to implement than basic linear queues.

The program must correctly manage:

* The front position
* The rear position
* The queue capacity
* Wrap-around behavior
* Empty conditions
* Full conditions

The program must also correctly determine when the queue has reached the end of the array and needs to wrap back to the beginning.

If these conditions are not handled correctly, the program may incorrectly identify whether the queue is full or empty.

# Summary

A queue is a **FIFO (First In, First Out)** data structure where elements are added at the rear and removed from the front. The primary operations include enqueue(), dequeue(), isEmpty(), isFull(), and displayAll().

A basic linear array queue is simple to implement but can leave unused positions at the beginning of the array after elements are removed. This can result in inefficient use of the available array space.

A circular queue solves this problem by allowing the rear to wrap around to the beginning of the array. This allows previously unused positions to be reused without shifting the existing elements.

The key concept behind a circular queue is the ability to move from the final array position back to the first position. This makes circular queues especially useful for systems where elements are continuously being added and removed.

Understanding queues and circular queues is important because these data structures are commonly used in operating systems, networking, scheduling, buffering, and other applications where data must be processed in the order it arrives.
