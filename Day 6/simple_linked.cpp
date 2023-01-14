#include <iostream>

using namespace std;

class List 
{
public:
    int data;
    List* next;

    List(int data) 
    {
        this->data = data;
        this->next = NULL;
    }
};


List *head = NULL;

void Insert(int data) 
{
    List* temp = new List(data);
    temp->next = head;
    head = temp;
}

void Print() 
{
    List* temp = head;
    while (temp != NULL) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
}