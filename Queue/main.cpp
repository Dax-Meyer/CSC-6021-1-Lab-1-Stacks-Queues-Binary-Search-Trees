#include "Queue.h"
#include<iostream>
#include<limits>
using namespace std;

/////////////////////////////////////////////////////////////////////////////

void showWelcome ();
void showMenu ();
int validate (int choice);
bool process (int choice);
void function1 ();
void function2 ();
void function3 ();
void function4 ();

Queue<int, 10> q;
/////////////////////////////////////////////////////////////////////////////

int
main ()
{
  bool AGAIN = true;
  int choice = 0;

  showWelcome ();
  do
    {
      showMenu ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validate (choice);
      AGAIN = process (choice);

    }
  while (AGAIN);
}

/////////////////////////////////////////////////////////////////////////////
// showMenu function
/////////////////////////////////////////////////////////////////////////////
void
showMenu ()
{
  cout << "**************************" << endl;
  cout << "1. Enqueue value to Queue" << endl;
  cout << "2. Dequeue value from Queue" << endl;
  cout << "3. Peek at value in Queue" << endl;
  cout << "4. Display all values in Queue" << endl;
  cout << "5. Exit" << endl;
  cout << "**************************" << endl;
}

/////////////////////////////////////////////////////////////////////////////
// validate function
/////////////////////////////////////////////////////////////////////////////
int
validate (int choice)
{
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
      cin.clear ();
      cin.ignore (numeric_limits < streamsize >::max (), '\n');
      cout << "You have entered wrong input." << endl;
      cin >> choice;
    }
  return choice;
}

/////////////////////////////////////////////////////////////////////////////
// showWelcome Function
/////////////////////////////////////////////////////////////////////////////
void
showWelcome ()
{
  cout << "///////////////////////////////" << endl;
  cout << "Welcome to the Queue Demo" << endl;
  cout << "///////////////////////////////" << endl;
}

/////////////////////////////////////////////////////////////////////////////
// process function
/////////////////////////////////////////////////////////////////////////////
bool
process (int choice)
{

  bool AGAIN = true;

  enum Options
  { ENQUEUE = 1, DEQUEUE, PEEK, DISPLAY, EXIT };

  switch (choice)
    {
    case ENQUEUE:
      function1 ();
      break;

    case DEQUEUE:
      function2 ();
      break;

    case PEEK:
      function3 ();
      break;

    case DISPLAY:
      function4 ();
      break;

    case EXIT:
      cout << "Exiting... Thank you for using the program!" << endl << endl;
      AGAIN = false;

    }

  return AGAIN;
}

/////////////////////////////////////////////////////////////////////////////
// function1 function
/////////////////////////////////////////////////////////////////////////////
void
function1 ()
{
int value;
while (true) {
        cout << "Enter a number (0 to quit): ";
        cin >> value;
if(cin.fail())
{
cin.clear();
cin.ignore(1000, '\n');
cout << "Invalid Input! Number is too large or not a number. " << endl;
continue;
}
 if (value == 0) break;

        try {
            q.enqueue(value);
            cout << "Inserted " << value << " successfully!\n";
        } catch (const std::out_of_range& e) {
            cout << "Range Error: " << e.what() << "\n";
            // loop continues — user can try again
        } catch (const std::invalid_argument& e) {
            cout << "Invalid Input: " << e.what() << "\n";
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// function2 function
/////////////////////////////////////////////////////////////////////////////
void
function2 ()
{
int value = q.dequeue();
cout << "Dequeued: " << value << endl;
}

/////////////////////////////////////////////////////////////////////////////
// function3 function
/////////////////////////////////////////////////////////////////////////////
void
function3 ()
{
  cout << "Start of Queue: " << q.peek() << endl;
cout << "Value was not removed from queue" << endl;
}

/////////////////////////////////////////////////////////////////////////////
// function4 function
/////////////////////////////////////////////////////////////////////////////
void
function4 ()
{
  cout << "Queue: ";  q.displayAll();
}

/////////////////////////////////////////////////////////////////////////////
