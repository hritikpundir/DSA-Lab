#include<iostream>
using namespace std;

void deleteElement(int arr[],int size,int pos){
    if(size<=0 || size>30 || pos<=0 || pos>size){
        cout<<"Invalid choice!!";
        exit(0);
    }
    else{
    for(int i=pos-1; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    size--;
    }

    cout<<"Elements after deletion of the element"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"  ";
    }
}

int main(){
    int size ,pos;
    cout<<"Enter the size of the array:";
    cin>>size;

    int a[30];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<size;++i){
        cin>>a[i];
    }

    cout<<"Enter the position to be removed: ";
    cin >>pos;

    deleteElement(a,size,pos);

    
    return 0;
}