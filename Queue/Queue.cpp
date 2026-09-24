//////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
Queue<QUEUETYPE, CAPACITY>::Queue()
{
start = 0;
end = 0;
}
//////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
void Queue<QUEUETYPE, CAPACITY>::enqueue(const QUEUETYPE& value)
{
// ── Numeric validation ─────────────────────────────
    if constexpr (std::is_arithmetic<QUEUETYPE>::value) {
        if (value < 0 || value > 100) {
            throw std::out_of_range("Number must be between 1 and 100.");
        }
    }
if(this->isFull())
{
cout << "Error Queue is Full" << endl;
return;
}
end = (end + 1) % CAPACITY;
data[end] = value;
}
///////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
QUEUETYPE Queue<QUEUETYPE, CAPACITY>::dequeue()
{
if(this->isEmpty())
{
cout << "Error queue is empty" << endl;
}
return start = (start + 1) % CAPACITY;
}
//////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
QUEUETYPE Queue<QUEUETYPE, CAPACITY>::peek()
{
if(this->isEmpty())
{
cout << "Error queue is empty" << endl;
}
return data[(start + 1) % CAPACITY];
}
///////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
void Queue<QUEUETYPE, CAPACITY>::displayAll() const
{
    if (this->isEmpty())
    {
        cout << "Error: queue is empty" << endl;
        return;
    }

    int i = (start + 1) % CAPACITY;

    while (true)
    {
        cout << data[i] << " ";

        if (i == end)
            break;

        i = (i + 1) % CAPACITY;
    }

    cout << endl;
}
/////////////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
bool Queue<QUEUETYPE, CAPACITY>::isEmpty()const
{
if(start == end)
return true;
return false;
}
/////////////////////////////////////////////////
template<typename QUEUETYPE, int CAPACITY>
bool Queue<QUEUETYPE, CAPACITY>::isFull()const
{
if((end + 1) % CAPACITY == start)
{
return true;
}
return false;
}
//////////////////////////////////////////////////
