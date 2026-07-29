#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> majorityElementTwo(vector<int> &nums)
{

    int n = nums.size();

    vector<int> result;

    unordered_map<int, int> mpp;

    int mini = int(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;

        if (mpp[nums[i]] == mini)
        {
            result.push_back(nums[i]);
        }
        if (result.size() == 2)
            break;
    }
    return result;
}
int main()
{

    vector<int> arr = {11, 33, 33, 11, 33, 11};

    vector<int> ans = majorityElementTwo(arr);

    // Print the majority elements found
    cout << "The majority elements are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}