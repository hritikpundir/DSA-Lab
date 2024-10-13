#include<iostream>
using namespace std;

int binarySearch(int arr[], int size,int target){
    int left = 0;
    int right = size-1;

    while(left <= right){
       int mid = (left+right)/2;
       
       if(arr[mid] == target){
         return mid;
       }
       else if(target < arr[mid]){
          right = mid-1;
       }
       else{
         left = mid+1;
       }
    }
}

int main(){
    
     int n,target;
    cout<<"Enter the size of the array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    cout<<"Enter the element to search in the array:"<<endl;
    cin>>target;

    int result = binarySearch(arr,n,target);
    if(result == -1){
        cout<<"Element not present in the array!";
    }
    else{
        cout<<"The index of the target element is "<<result;
    }

    return 0;
}