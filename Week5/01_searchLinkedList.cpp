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
}  *head = 0, *temp;

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

    if (temp == 0)
    {
        cout << "Empty list!!" << endl;
        return;
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

bool searchElement(int d)
{
    node *temp = head;
    while (temp != 0)
    {
        if (temp->data == d)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    createSinglyList();

    display();
    int d;
    cout << "Enter Data to be searched: ";
    cin >> d;
    if (searchElement(d))
        cout << "The element is present in the list!";
    else
        cout << "The element is not present in the list!";

    return 0;
}