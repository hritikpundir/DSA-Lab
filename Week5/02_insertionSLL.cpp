#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next; // Added the 'next' pointer

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *head = 0, *tail = 0, *temp = 0; // Initialize tail and temp

int choice = 1;

void createSinglyList()
{
    while (choice)
    {
        int d;
        cout << "Enter data in newnode: ";
        cin >> d;
        node *newnode = new node(d);

        if (head == 0)
        { // because we don't want to lose the reference to the first node
            head = temp = tail = newnode; // Update tail as well
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            tail = newnode; // Keep tail updated to the last node
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
    newnode->next = head;
    head = newnode;

    // If the list was empty, update tail as well
    if (tail == NULL)
    {
        tail = newnode;
    }
}

void insertEnd()
{
    // creating node
    int d;
    cout << "Enter data in inserting node: ";
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
    tail = newnode; // Update tail to point to the new last node
}

void insertAnypos(int length)
{
    int pos, i = 1;
    cout << "Enter the position to insert the node: ";
    cin >> pos;

    if (pos < 1 || pos > length + 1) // Allow insertion at (length + 1)
    {
        cout << "Invalid position!!" << endl;
    }
    else if (pos == 1)
    {
        insertBegin();
    }
    else if (pos == length + 1) // Handle insertion at the end
    {
        insertEnd();
    }
    else
    {
        // creating node
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
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    temp = head;
    if (head == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }
    
    while (temp != nullptr)
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
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    createSinglyList();

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
    cout << "Data Elements after inserting new node at any random position: " << endl;
    display();

    return 0;
}
