#include<iostream>
using namespace std;

void insertElement(int arr[],int size,int pos){
     if(size<=0 || size>30 || pos<=0 || pos>size+1){
        cout<<"Invalid choice!!";
        exit(0);
    }
    else{
        int x;
        cout<<"Enter the element to insert: ";
        cin>>x;
        
        for(int i=size-1;i>=pos-1;i--){
        arr[i+1] = arr[i];
       }
       arr[pos-1] = x;
       size++;

       cout<<"Elements after insertion of new element"<<endl;
      for(int i=0; i<size; i++){
        cout<<arr[i]<<"  ";
    }
    }
}

int main(){
    int n ,pos;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int a[30];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    
    cout<<"Enter the position to insert the element: ";
    cin >>pos;

    insertElement(a,n,pos);

    
    return 0;
}