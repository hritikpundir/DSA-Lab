
#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number) {
    int originalNumber = number;
    int sum = 0;
    int numberOfDigits = 0;

    // Calculate the number of digits in the number
    int temp = number;
    while (temp != 0) {
        numberOfDigits++;
        temp /= 10;
    }

    // Calculate the sum of the powers of its digits
    temp = number;
    while (temp) {        
        int digit = temp % 10;
        sum += pow(digit, numberOfDigits);
        temp = temp/10;
      
    }

    return sum == originalNumber;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
 return 0;
}
