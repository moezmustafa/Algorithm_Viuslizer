#include <iostream>


using namespace std;


class Stack
{
public:
    int top;
    int size;
    int *arr;

    Stack(int s)
    {
        top = -1;
        size = s;
        arr = new int[size];
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = arr[top];
        top--;
        return data;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    return 0;
}