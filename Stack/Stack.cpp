//////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
Stack<STACKTYPE, CAPACITY>::Stack() : topIndex(-1) {}
////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
void Stack<STACKTYPE, CAPACITY>::push(const STACKTYPE& value)
{
 if constexpr (std::is_arithmetic<STACKTYPE>::value) {
        if (value < 0 || value > 100) {
            throw std::out_of_range("Number must be between 1 and 100.");
        }
    }

if (isFull())
{
cout << "Error: push() called on full stack. (max: " << CAPACITY << ")\n";
return;
}
data[++topIndex] = value;
}
////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
STACKTYPE Stack <STACKTYPE, CAPACITY>::pop()
{
if(this->isEmpty())
{
cout << "Error: called pop() on a Empty Stack.\n";
}
return data[topIndex--];
}
//////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
STACKTYPE& Stack<STACKTYPE, CAPACITY>::peek()
{
if(isEmpty())
{
cout << "Error: Stack is Empty\n";
}
return data[topIndex];
}
///////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
bool Stack<STACKTYPE, CAPACITY>::isEmpty()const
{
return topIndex == -1;
}
////////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
bool Stack<STACKTYPE, CAPACITY>::isFull()const
{
return topIndex == CAPACITY -1;
}
//////////////////////////////////////////////////
template<typename STACKTYPE, int CAPACITY>
void Stack<STACKTYPE, CAPACITY>::displayAll()const
{
if (isEmpty()) {
        cout << "[ empty stack ]\n";
        return;
}
cout << "Stack Top to Bottom): " << endl;
for(int i = topIndex; i >= 0; --i)
 cout << "|" << data[i] << "|" << endl;
}

