#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubKadane(vector<int> &arr)
{

    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }

        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}
int main()
{

    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "maximumSubArray " << maxSubKadane(arr) << endl;
    return 0;

    return 0;
}