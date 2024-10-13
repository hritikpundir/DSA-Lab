#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = 0;
    }
} *tail = 0,*head = 0;

void createList(int d){
   node *newnode = new node(d);

   if(tail == 0){
      
      head = tail = newnode;
      
   }
   else{
    
     tail->next = newnode;
     tail = tail->next;
   }
}

void display(){
    
    if(tail == 0){
        cout<<"Empty list!!"<<endl;
    }
    else{
        node *temp = head;

        while(temp != 0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
        cout<<endl;
    }
}

bool searchElement(int d){
    node *temp = head; 
    while(temp != 0){
        if(temp->data == d) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    createList(700);
    createList(45);
    createList(51);
    createList(33);
    createList(15);
    display();
    int d;
    cout<<"Enter Data to be searched: ";
    cin>>d;
    if (searchElement(d))
    cout<<"The element is present in the list!";
    else
    cout<<"The element is not present in the list!";

    return 0;
}