#include <iostream>
using namespace std;


void generateFibonacci(int N) {
    int first = 0, second = 1, next;
   
    cout << "The first " << N << " terms of the Fibonacci sequence are "<<endl;

    for (int i = 1; i <= N; ++i) {
        if (i == 1) {
            cout << first << " ";
            continue;
        }
        if (i == 2) {
            cout << second << " ";
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        cout << next << " ";
    }
    cout << endl;
}

void setNum(){
    int N;
    cout << "Enter the number of terms: ";
    cin >> N;

     if (N <= 0) {
        cout << "Please enter a positive integer." << endl;
        setNum();
        return ;
    }
    generateFibonacci(N);
}

int main() {
    setNum();
    
return 0;
}
