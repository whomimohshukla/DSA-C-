#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;

    while (start <=end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1; // Target not found
}
int main()
{
    int target = 6; // target element to search
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};

    int ind = binarySearch(a, target);

    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: " << ind << endl;

    return 0;
}