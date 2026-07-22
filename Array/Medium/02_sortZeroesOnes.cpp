#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortZeroOneTwo(vector<int> &arr)
{

    int low = 0;
    int medium = 0;
    int high = arr.size() - 1;

    while (medium < high)
    {
        if (arr[medium] == 0)
        {
            swap(arr[medium], arr[low]);
            low++;
            medium++;
        }
        else if (arr[medium] == 1)
        {
            medium++;
        }
        else
        {
            swap(arr[medium], arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortZeroOneTwo(nums);

    for (int val : nums)
        cout << val << " ";

    return 0;
}