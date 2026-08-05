#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upperBound(vector<int> &arr, int n, int x)
{

    int start = 0;
    int end = arr.size() - 1;
    int ans = n;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 5, 8, 15, 19}; // Sorted input array
    int n = arr.size();                  // Size of array
    int x = 9;                           // Target value

    int ind = upperBound(arr, n, x); // Call method to find lower bound

    cout << "The Upper bound is the index: " << ind << "\n"; // Output the result

    return 0;
}