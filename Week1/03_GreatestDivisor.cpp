#include <iostream>
using namespace std;

int gcd(int f, int g) {
    while (g != 0) {
        int remainder = f % g;
        f = g;
        g = remainder;
    }
    return f;    //f will be the greatest common divisor
}

int main() {
    int f, g;
    cout << "Enter two positive integers: ";
    cin >> f >> g;

    if (f <= 0 || g <= 0) {
        cout << "Both numbers must be positive integers." << endl;
        return 1;
    }

    int result = gcd(f, g);
    cout << "The Greatest Common Divisor of " << f << " and " << g << " is " << result  << endl;

  return 0;
}