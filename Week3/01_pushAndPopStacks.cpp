#include<iostream>
using namespace std;
 
int top = -1;

void push(int arr[],int x){
   top++;
   arr[top] = x;
}

void pop(){
    if(top == -1){
        cout<<"Underflow condition!! ";
    }
    else{
        top--;
    }
}

void display(int arr[]){
    for(int i=0; i<=top; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size,add;
    cout<<"Enter the size of the stack: ";
    cin>>size;

    int arr[size];
    
    cout<<"Enter number of elements you want to push in the stack: ";
    cin>>add;

    while(add && add<=size){
        int x;
        cout<<"Enter the element to push: ";
        cin>>x;
        push(arr, x);
        add--;
    }

     int sub;
     cout<<"Enter number of elements you want to pop from the stack: ";
     cin>>sub;

     for(int i=0; i<sub; i++){
        pop();
     }

     cout<<"The stack elements are: "<<endl;
     display(arr);

    return 0;
}