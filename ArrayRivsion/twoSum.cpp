#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumTwoPointer(vector<int> &arr, int target)
{
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return {left, right};
        else if (sum < target)
            ++left; // need a bigger sum
        else
            --right; // need a smaller sum
    }
    return {}; // no pair
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoPointer(arr, target);

    if (!result.empty())
        cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    else
        cout << "No pair found\n";

    return 0;
}