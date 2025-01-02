#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(const vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // No majority element
    }
}

int main() {
    cout << "Enter the elements of the array separated by spaces (end input with Enter):" << endl;
    vector<int> nums;
    int num;

    // Reading user input
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') break; // Stop input on Enter
    }

    if (nums.empty()) {
        cout << "The array is empty. Please enter valid numbers." << endl;
        return 0;
    }

    int majorityElement = findMajorityElement(nums);
    if (majorityElement != -1) {
        cout << "The majority element is: " << majorityElement << endl;
    } else {
        cout << "There is no majority element in the array." << endl;
    }

    return 0;
}
