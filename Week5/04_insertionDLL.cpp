//head points to starting node
//tail points to the end node

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node * prev;

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

node *head = 0 , *tail , *temp;
 
int choice = 1;

void createDoublyList(int d){
    
       node *newnode = new node(d);

       if(head == 0){    //because we don't want to loose the reference to first node
          head = tail = newnode;
       }
       else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = tail->next;
       }
       
}

void insertBegin(int d){
    //creating node
    node* newnode = new node(d);

    //inserting node at beginning
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int d){
    //creating node
    node* newnode = new node(d);
    //inserting node at end
    if(tail != nullptr){
        tail->next = newnode;
    } else {
        head = newnode;
    }
    tail = newnode;
}

void insertAnypos(int length, int d){

    int pos,i=1;
    cout<<"Enter the position to insert the node: ";
    cin>>pos;

    if(pos<1 || pos>length ){
      cout<<"Invalid postion!!"<<endl;
    }

    else if(pos == 1){
        insertBegin(d);
    }
    else{
      //creating node
    node* newnode = new node(d);
     //inserting at any position
     node * temp = head;
     while(i < pos-1){
        temp = temp->next;
        i++;
     }
     newnode->prev = temp;
     newnode->next =  temp->next;
     temp->next = newnode;

     newnode->next->prev = newnode;
      }
}

void display(){
    temp = head;
    while(temp != 0){

        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(){
    int count = 0;
    temp = head;
    while(temp != 0){
        count ++;
        temp = temp->next;
    }
    return count;
}


int main(){
tail = head;
createDoublyList(4);  
createDoublyList(3);  
createDoublyList(2);  
createDoublyList(1);  
cout<<"Initial Linked list created!! "<<endl;

cout<<"Data Elements before inserting new node: "<<endl;
display();

insertBegin(5);
cout<<"Data Elements after inserting new node at beginning: "<<endl;
display();

insertEnd(0);
cout<<"Data Elements after inserting new node at end: "<<endl;
display();

int length = getLength();
insertAnypos(length,100);
cout<<"Data Elements after inserting new node at any random position: "<<endl;
display();
    return 0;
}
