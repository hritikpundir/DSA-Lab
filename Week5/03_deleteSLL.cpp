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
} *temp,*tail = 0,*head = 0;

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

void deleteBegin(){
    if(head == 0){
        cout<<"List is empty!! "<<endl;
        return;
    }
    else{
        temp = head;
         head = head->next;
        
        delete(temp);
    }
}

void deleteEnd(){
    tail = head;
    while(tail != 0){
        tail = tail->next;
    }
    if(tail == 0){
       cout<<"List is empty!!"<<endl;
       return;
    }
    else{
         temp = tail->next;
        delete(temp);
    }
}


void deleteAnyPos(int length){
    node *temp = head;
    node *nextnode;

    int pos,i=1;
    cout<<"Enter the Node position to delete: ";
    cin>>pos;

    if(pos == 1){
        deleteBegin();
    }
     else
    {
    while(i < pos-1){
    temp = temp->next;
    i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete(nextnode);
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
    createList(700);
    createList(45);
    createList(51);
    createList(33);
    createList(15);
    display();
     temp = head;
    cout<<"Data elements after deletion of node"<<endl;
deleteBegin();
display();
deleteEnd();
display();

int length = getLength(); 
deleteAnyPos(length);
display();
    

    return 0;
}