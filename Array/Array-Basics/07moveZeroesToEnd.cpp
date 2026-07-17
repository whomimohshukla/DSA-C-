#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveZeroes(vector<int> &nums)
{

    int j = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    // If no zero found, return
    if (j == -1)
        return;

    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    // Print the result
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
    return 0;
}


// | Step  | i | j | Action           | Array             |
// | ----- | - | - | ---------------- | ----------------- |
// | Start | - | 1 | First zero found | `1 0 2 3 0 4 0 1` |
// | 1     | 2 | 1 | Swap 2 ↔ 0       | `1 2 0 3 0 4 0 1` |
// | 2     | 3 | 2 | Swap 3 ↔ 0       | `1 2 3 0 0 4 0 1` |
// | 3     | 4 | 3 | Zero found, skip | `1 2 3 0 0 4 0 1` |
// | 4     | 5 | 3 | Swap 4 ↔ 0       | `1 2 3 4 0 0 0 1` |
// | 5     | 6 | 4 | Zero found, skip | `1 2 3 4 0 0 0 1` |
// | 6     | 7 | 4 | Swap 1 ↔ 0       | `1 2 3 4 1 0 0 0` |
