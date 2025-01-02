// head points to starting node
// tail points to the end node

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

node *head = 0, *tail, *temp;

int choice = 1;

void createDoublyList()
{
    while (choice)
    {
        int d;
        cout << "Enter data in newnode: ";
        cin >> d;
        node *newnode = new node(d);

        if (head == 0)
        { // because we don't want to loose the reference to first node
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
        }
        cout << "Do you want to continue (0,1): ";
        cin >> choice;
    }
}

void insertBegin()
{
    // creating node
    int d;
    cout << "Enter data in inserting node: ";
    cin >> d;
    node *newnode = new node(d);

    // inserting node at beginning
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    // creating node
    cout << "Enter data in inserting node: ";
    int d;
    cin >> d;
    node *newnode = new node(d);

    // inserting node at end
    if (tail != nullptr)
    {
        tail->next = newnode;
    }
    else
    {
        head = newnode;
    }
    tail = newnode;
}

void insertAnypos(int length)
{

    int pos, i = 1;
    cout << "Enter the position to insert the node: ";
    cin >> pos;

    if (pos < 1 || pos > length)
    {
        cout << "Invalid postion!!" << endl;
        return;
    }

    else if (pos == 1)
    {
        cout << "Data Elements after inserting new node at position: " << pos << endl;

        insertBegin();
    }
    else
    {
        // creating node
        cout << "Data Elements after inserting new node at position: " << pos << endl;

        int d;
        cout << "Enter data in inserting node: ";
        cin >> d;
        node *newnode = new node(d);

        // inserting at any position
        node *temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;

        newnode->next->prev = newnode;
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    tail = head;
    createDoublyList();
    cout << "Initial Linked list created!! " << endl;

    cout << "Data Elements before inserting new node: " << endl;
    display();

    insertBegin();
    cout << "Data Elements after inserting new node at beginning: " << endl;
    display();

    insertEnd();
    cout << "Data Elements after inserting new node at end: " << endl;
    display();

    int length = getLength();
    insertAnypos(length);
    display();
    return 0;
}
