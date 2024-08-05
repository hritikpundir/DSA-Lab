#include<iostream>
using namespace std;

void calculateDigits(int num){
int numberOfDigits = 0;
  int temp = num;
    while (temp != 0) {
        numberOfDigits++;
        temp /= 10;
    }
    cout<<"The number of digits in "<<num<<" are: "<<numberOfDigits;
}

int main(){
    int num;
    cout<<"Enter the integer number: ";
    cin>>num;
    calculateDigits(num);
    
    return 0;
}