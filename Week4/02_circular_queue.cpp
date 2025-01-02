#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *front = 0;
node *rear = 0;

int choice = 1;

void enqueue()
{
    while (choice)
    {
        int x;
        cout << "Enter the data inside newnode ";
        cin >> x;
        node *newnode = new node(x);

        if (rear == 0)
        {
            front = rear = newnode;
            rear->next = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
        cout << "Do you want to continue (0,1): ";
        cin >> choice;
    }
}

void display()
{

    if (rear == 0)
    {
        cout << "List is empty!!" << endl;
    }
    else
    {
        node *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
}

void dequeue()
{
    node *temp = front;
    if (front == 0 && rear == 0)
    {
        cout << "List is empty!!";
        return;
    }
    else if (front == rear)
    {
        front = rear = 0;
        delete (temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        delete (temp);
    }
}

int main()
{
    enqueue();
    display();
    dequeue();
    display();
    return 0;
}