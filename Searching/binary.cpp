#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (x == arr[mid])
            return mid;
        else if (arr[mid] < x)
            return binarySearchRecursive(arr, mid + 1, right, x);
        else
            return binarySearchRecursive(arr, left, mid - 1, x);
    }
    return -1;
}

// main function
int main()
{
    cout << "-- Binary Search Algorithm --" << endl;

    int num;
    int myArr[10];
    int output = -1;

    cout << "Enter 10 integers in ASCENDING order" << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> myArr[i];
    }

    cout << "Enter one number that you want to search in the Array: ";
    cin >> num;

    // output = binarySearch(myArr, 0, 9, num);
    output = binarySearchRecursive(myArr, 0, 9, num);

    if (output == -1)
    {
        cout << "No match found" << endl;
    }
    else
    {
        cout << "Match found at index position: " << output << endl;
    }

    return 0;

    return 0;
} // end of main