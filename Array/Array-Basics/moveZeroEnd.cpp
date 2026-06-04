#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 // Function to move zeroes to the end
    void moveZeroes(vector<int>& nums) {
        // Pointer to the first zero
        int j = -1;

        // Find the first zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero found, return
        if (j == -1) return;

        // Start from the next index of first zero
        for (int i = j + 1; i < nums.size(); i++) {
            // If current element is non-zero
            if (nums[i] != 0) {
                // Swap with nums[j]
                swap(nums[i], nums[j]);
                // Move j to next zero
                j++;
            }
        }
    }
int main()
{

    vector<int> nums = {0, 1, 0, 3, 12};
   moveZeroes(nums);

    // Print the result
    for (int num : nums) cout << num << " ";
    cout << endl;
 return 0;
}