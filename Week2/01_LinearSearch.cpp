#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cout << "Enter the size of the array:";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search in the array:" << endl;
    cin >> target;

    int result = linearSearch(arr, n, target);
    if (result == -1)
    {
        cout << "Element not present in the array!";
    }
    else
    {
        cout << "The index of the target element is " << result;
    }

    return 0;
}