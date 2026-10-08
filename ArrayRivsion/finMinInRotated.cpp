#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int> &arr)
{
    int left = 0;

    int right = arr.size();

    while (left < right)
    {
        int mid = left + (left - right) / 2;

        if (arr[mid] > arr[right])
        {
            left = mid + 1;
        }
        else
        {
            // Minimum is at mid or to the left
            right = mid;
        }
    }

    return arr[left];
}
int main()
{
    vector<int> arr{5, 6, 7, 1, 2, 3, 4};

    cout << "minimum in rotated array" << findMin(arr) << endl;

    return 0;
}