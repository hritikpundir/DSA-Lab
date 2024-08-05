#include <iostream>
using namespace std;

void generateTable(int num, int range) {
    for (int i = 1; i <= range; ++i) {
        cout << num << " * " << i << " = " << num * i << endl;
    }
}

int main() {
    int number, range;

    cout << "Enter the number for which you want to generate the multiplication table: ";
    cin >> number;

    cout << "Enter the range up to which you want to generate the multiplication table: ";
    cin >> range;

    generateTable(number, range);

    return 0;
}