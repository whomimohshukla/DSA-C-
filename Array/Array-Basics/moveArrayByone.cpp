#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void rotateArrayByOne(vector<int>&arr)

{


    int temp=arr[0];

    for (int i = 1; i <arr.size(); i++)
    {
        arr[i-1]=arr[i];
    }

    // put first in last

    arr[arr.size()-1]=temp;
    
}
int main()
{
  
    vector<int> nums = {1, 2, 3, 4, 5};

    rotateArrayByOne(nums);

    for (int num : nums) {
        cout << num << " "; // Output the rotated array
    }

 return 0;
}