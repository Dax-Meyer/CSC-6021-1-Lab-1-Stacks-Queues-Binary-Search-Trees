#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template<typename QUEUETYPE, int CAPACITY = 10 >
class Queue
{
public:
//consturctor
Queue();

void enqueue(const QUEUETYPE& value);
QUEUETYPE dequeue();
QUEUETYPE peek();

bool isEmpty()const;
bool isFull()const;

void displayAll() const;

private:
QUEUETYPE data[CAPACITY];
int start;
int end;

};
#include "Queue.cpp"
#endif
