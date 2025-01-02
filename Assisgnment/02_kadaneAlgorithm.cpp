#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSumSubarray(const vector<int>& arr) {
    int maxCurrent = arr[0];
    int maxGlobal = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }

    return maxGlobal;
}

int main() {
    cout << "Enter the elements of the array separated by spaces (end input with Enter):" << endl;
    vector<int> arr;
    int num;

    // Reading user input
    while (cin >> num) {
        arr.push_back(num);
        if (cin.peek() == '\n') break; // Stop input on Enter
    }

    if (arr.empty()) {
        cout << "The array is empty. Please enter valid numbers." << endl;
        return 0;
    }

    int result = maxSumSubarray(arr);
    cout << "The maximum sum of a subarray is: " << result << endl;

    return 0;
}
