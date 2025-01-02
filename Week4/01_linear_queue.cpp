#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *front = 0;
Node *rear = 0;

int choice = 1;

void enqueue()
{
    while (choice)
    {
        int x;
        cout << "Enter the data inside newnode ";
        cin >> x;
        Node *newnode = new Node(x);

        if (front == 0 && rear == 0)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        cout << "Do you want to continue (0,1): ";
        cin >> choice;
    }
}

void display()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty!";
        return;
    }

    else
    {
        Node *temp;
        temp = front;
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void dequeue()
{
    if (front == 0 && rear == 0)
    {
        cout << "Queue is empty!";
        return;
    }
    else
    {
        Node *temp = front;
        front = front->next;
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