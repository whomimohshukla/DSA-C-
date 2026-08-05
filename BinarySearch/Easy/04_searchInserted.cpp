#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int ans = n;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= x)
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
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();
    int x = 9;

    int ind = lowerBound(arr, n, x);

    cout << "The insertion index is: " << ind << endl;

    return 0;
}