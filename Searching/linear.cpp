#include <iostream>

using namespace std;

void linearSearch(int a[], int n)
{
    int temp = -1;

    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
        }
    }
    if (temp == -1)
    {
        cout << "No Element Found" << endl;
    }
}

// main function
int main()
{
    cout << "-- Linear Search --" << endl;
    int arr[5] = {1, 22, 34, 5, 7};
    cout << "Please enter an element to search:" << endl;
    int num;
    cin >> num;

    linearSearch(arr, num);

    return 0;
} // end of main