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
        this->next = 0;
    }
} *tail, *temp, *head = 0;

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
        { // because we don't want to loose the reference to first node
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        cout << "Do you want to continue (0,1): ";
        cin >> choice;
    }
}

void display()
{

    if (head == 0)
    {
        cout << "Empty list!!" << endl;
    }
    else
    {
        node *temp = head;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

void deleteBegin()
{
    if (head == 0)
    {
        cout << "List is empty!! " << endl;
        return;
    }
    else
    {
        temp = head;
        head = head->next;

        delete (temp);
    }
}

void deleteEnd()
{
    temp = head;
    while (temp->next != 0)
    {
        tail = temp;
        temp = temp->next;
    }
    if (head == 0)
    {
        cout << "List is empty!!" << endl;
        return;
    }
    else
    {
        tail->next = 0;
        delete (temp);
    }
}

void deleteAnyPos(int length)
{

    int pos, i = 1;
    cout << "Enter the Node position to delete: ";
    cin >> pos;
    cout << "Data elements after deletion of node at position " << pos << endl;

    if (pos < 1 || pos > length)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    else if (pos == 1)
    {

        deleteBegin();
    }
    else
    {
        node *temp = head;
    node *nextnode;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        delete(nextnode);
    }
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
    createSinglyList();

    display();
    temp = head;
    cout << "Data elements after deletion of node at begin" << endl;
    deleteBegin();
    display();
    cout << "Data elements after deletion of node at end" << endl;
    deleteEnd();
    display();

    int length = getLength();
    deleteAnyPos(length);
    display();

    return 0;
}