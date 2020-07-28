/* 
>> Time: O(n+k)
>> Space O(n+k)
k = range of elements
***********************
COUNTING SORT ALGORITHM: 
Counting Sort is a sorting algorithm that sorts the elements of an array by counting the number
of occurrences of each unique element in the array.
Not a comparison sort.
The count is stored in an auxiliary array and the sorting is done by mapping the count
as an index of the auxiliary array.
***********************
STEPS:
1 - Take input array & range (n. of unique integer values involved)
2 - Create the output array of size same as input array.
    Create count array with size equal to the range & initialize values to 0.
3 - Count each element in the input array and place the count at the appropriate index of the
    count array.
4 - Modify the count array by adding the previous counts (cumulative). The modified count array 
    indicates the position of each object/element in the output array.
5 - Output each object from the input array into the sorted output array followed by decreasing its
    count by 1.
6 - Print the sorted output array.
*/

#include <iostream>

using namespace std;

void CountingSort(int input_arr[], int s, int r)
{
    int output_array[s];
    int count_array[r];

    // Initialize all element to 0 in count array
    for (int i = 0; i < r; i++)
    {
        count_array[i] = 0;
    }

    // Takes the count of all elements in the input array
    for (int i = 0; i < s; i++)
    {
        ++count_array[input_arr[i]];
    }

    // Cumulative count of count array to get the positions of elements to be stored in the output
    // array
    for (int i = 1; i < r; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    // Placing input array elements into output array in proper positions such that the result
    // is a sorted array in ascending order
    for (int i = 0; i < s; i++)
    {
        output_array[--count_array[input_arr[i]]] = input_arr[i];
    }

    // Copy output array elements to input array
    for (int i = 0; i < s; i++)
    {
        input_arr[i] = output_array[i];
    }
}

// main function
int main()
{
    cout << "-- Counting Sort --" << endl;

    int size = 0;
    int range = 10; // The number of unique elements

    cout << "Enter Size of array: ";
    cin >> size;
    int myArray[size];

    cout << "Enter " << size << " integers in any order in range of 0-9: ";
    for (int i = 0; i < size; i++)
    {
        cin >> myArray[i];
    }

    cout << "Before Sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << endl;

    CountingSort(myArray, size, range); // Counting Sort called. myArray is passed by address

    cout << "After Sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << endl;

    return 0;
} // end of main