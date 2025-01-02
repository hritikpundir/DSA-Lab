#include <iostream>
#include <vector>
using namespace std;

void dutchNationalFlag(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout <<endl;

    dutchNationalFlag(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
