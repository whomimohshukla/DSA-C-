#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

vector<int> rotateArray(vector<int> &nums, int k, string direction)
{

    int n = nums.size();

    // edge cases
    if (n == 0 || k == 0)
    {
        return nums;
    }

     k = k % n;

    if (direction=="right")
    {
        //first revrese all elements
        reverseArray(nums,0,n-1);

        //reverse k elements
        reverseArray(nums,0,k-1);
        //reverse all remaining elements
        reverseArray(nums,k,n-1);
       
    }
    else if (direction=="left")
    {
        //reverse k elements 
        reverseArray(nums,0,k);

        //reverse remaining elements
        reverseArray(nums,k,n-1);
        //reverse all elements
        reverseArray(nums,0,n-1);
       
    }

    return nums;
    
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string dir = "right";

    vector<int> result = rotateArray(nums, k, dir);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}