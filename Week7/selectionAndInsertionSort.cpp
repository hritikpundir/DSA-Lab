#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int choice;
    cout << "Choose sorting method:\n1. Selection Sort\n2. Insertion Sort\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(arr);
            cout << "Array sorted using Selection Sort: ";
            break;
        case 2:
            insertionSort(arr);
            cout << "Array sorted using Insertion Sort: ";
            break;
        default:
            cout << "Invalid choice!";
            return 1;
    }

    printArray(arr);

    return 0;
}
