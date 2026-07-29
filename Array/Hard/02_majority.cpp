#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find majority elements in an array
    vector<int> majorityElementTwo(vector<int>& nums) {
        
       int n=nums.size();

       vector<int>result;

       for (int i = 0; i < n; i++)
       {

        if(result.size()==0 || result[0]!=nums[i]){

            int cnt=0;

            for (int j = 0; j < n; j++)
            {
                if(nums[i]==nums[j]){
                    cnt++;
                }
                
            }

            if(cnt>(n/3)) {
                result.push_back(nums[i]);
            }

            
        }

        if(result.size()==2) break;
       
       }
       return result;
    }
};

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> ans = sol.majorityElementTwo(arr);
    
    // Print the majority elements found
    cout << "The majority elements are: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}