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

node *head = 0 , *temp,* tail;

int choice = 1;

void createDoublyList(){
    while(choice){
       int d;
       cout<<"Enter data in newnode: ";
       cin>>d;
       node *newnode = new node(d);

       if(head == 0){    //because we don't want to loose the reference to first node
          head = temp = newnode;
       }
       else{
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
       }
       cout<<"Do you want to continue (0,1): ";
       cin>>choice;
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

void deleteAtBegin(){
    if(head == 0){
        cout<<"List is empty!! "<<endl;
    }
    else{
        // temp = head;
         head = head->next;
        head->prev = 0;
        delete(temp);
    }
}

void deleteAtEnd(){
    temp = head;
    while(temp->next != 0){
        temp = temp->next;
    }
    if(temp == 0){
       cout<<"List is empty!!"<<endl;
    }
    else{
        tail = temp;
        temp->prev->next = 0;
        tail = tail->prev;
        delete(temp);
    }
}


void deleteAtAnyPos(int length){
    int pos,i=1;
    cout<<"Enter the position of the node to be deleted: ";
    cin>>pos;

    if(pos<1 || pos>length ){
      cout<<"Invalid postion!!"<<endl;
      return;
    }

    else if(pos == 1){
        deleteAtBegin();
    }

    else{
        temp = head;
        while(i < pos){
          temp = temp->next;
          i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
    }
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
    temp = head;
createDoublyList();  
cout<<"Data elements before deletion of node"<<endl;
display();
cout<<"Data elements after deletion of node from begin"<<endl;
deleteAtBegin();
display();
cout<<"Data elements after deletion of node from end"<<endl;
deleteAtEnd();
display();

int length = getLength(); 
deleteAtAnyPos(length);
display();
    return 0;
}