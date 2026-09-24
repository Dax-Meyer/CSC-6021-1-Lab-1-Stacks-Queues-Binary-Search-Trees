#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
template<typename STACKTYPE, int CAPACITY = 10>
class Stack
{
public:
//Constructor
Stack();

void push(const STACKTYPE& value);
STACKTYPE pop();
STACKTYPE& peek();

bool isEmpty()const;
bool isFull()const;

void displayAll() const;

private:
STACKTYPE data[CAPACITY];
int topIndex;


};
#include "Stack.cpp"
#endif
