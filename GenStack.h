#include <iostream>

using namespace std;

template <class T> class GenStack //creates GenStack as a template class
{
public: //public methods and variables for GenStack
    GenStack(); //constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(T d); //pushes element to the top of the stack
    T pop(); //pops off and returns top of stack
    T peek(); //aka top() looks at top of stack
    bool isFull(); //checks if stack is full
    bool isEmpty(); //checks if stack is empty
    void copyStack(); //copys over stack to bigger stack
    int getSize(); //gets size of stack

    int size; //var for size
    int newSize; //var for newsize
    int top; //var for top of stack

    T *myStack; // initial stackpointer to characters, pointer is a memory address
    T *newStack; //new stack when initial has met its capacity
};


template <class T> //declares template class
GenStack<T>::GenStack() //default constructor
{
    myStack = new T[100]; //creates stack with size 100
    size = 100;
    top = -1;
}

template <class T> //declares template class
GenStack<T>::GenStack(int maxSize) //argument constructor
{
    myStack = new T[maxSize]; //creates stack with given size
    size = maxSize;
    top = -1;
}

template <class T> //declares template class
GenStack<T>::~GenStack() // delete stack object
{
    delete myStack;
    cout << endl;
    cout << "Stack deleted" << endl;
}

template <class T> //declares template class
int GenStack<T>::getSize() //returns size
{
    return size;
}

template <class T> //declares template class
void GenStack<T>::push(T d)
{
    if(isFull()) //if stack is full
    {
        copyStack(); //copys over stack to new stack
        myStack[++top] = d; //then adds d to that new stack
    }
    else
    {
    myStack[++top] = d; //if stack isn't full adds d to top of stack
    }
}

template <class T> //declares template class
T GenStack<T>::pop() //pops off and returns top of stack
{
    try
    {
        if(top == -1) //if stack is empty
        {
            throw top; //throws exception
        }
        return myStack[top--]; //if stack is not empty, returns top

    }
    catch(int e) //catches exception
    {
        cout << "Exception: Stack is empty" << endl;
    }
}

template <class T> //declares template class
T GenStack<T>::peek() //looks at top of stack
{
    return myStack[top];
}

template <class T> //declares template class
bool GenStack<T>::isFull() //if stack is full
{
    return (top == size-1);
}

template <class T> //declares template class
bool GenStack<T>::isEmpty() //if stack is empty
{
    return (top == -1);
}

template <class T> //declares template class
void GenStack<T>::copyStack()
{
    newSize = size*2; //declares new size
    newStack = new T[newSize]; //creates new stack with that new size
    for(int i = 0; i < size; ++i) //forloop copies old stack over to new stack
    {
        newStack[i] = myStack[i];
    }
    myStack = new T[newSize]; //recreates initial stack with new size
    for(int i = 0; i < newSize; ++i) // forloop copies over new stack to initial stack
    {
        myStack[i] = newStack[i];
    }
    delete newStack; //deletes new stack
    size = newSize; //sets original size equal to new size
}
