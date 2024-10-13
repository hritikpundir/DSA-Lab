 #include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *front = 0;
Node *rear = 0;

void enqueue(int x){
    Node *newnode = new Node(x);

    if(front ==0 && rear== 0 ){
        front = rear =newnode;
    }
    else{
       rear->next = newnode;
       rear = newnode;
    }
}

void display(){
    if(front ==0 && rear== 0 ){
        cout<<"Queue is empty!";
        return;
    }

    else{
        Node *temp;
        temp = front;
        while(temp != 0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void dequeue(){
    if(front ==0 && rear== 0 ){
        cout<<"Queue is empty!";
        return;
    }
    else{
        Node *temp = front;
        front = front->next;
        delete(temp);
    }
}

int main(){
    enqueue(99);
    enqueue(929);
    enqueue(993);
    display();
    dequeue();
    display();
    return 0;
}