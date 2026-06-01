#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        // assume that the first element is minimum element
        // the minimum element is min_element

        int min_element = i;

        // itreate through and find the real minimum element from array
        //  from unsorted array

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_element])
            {
                min_element = j;
            }
        }
        // now swap the latest minimum for correct order

        swap(arr[i], arr[min_element]);
    }
}

void printArray(vector<int> &arr)
{
    for (int &val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}