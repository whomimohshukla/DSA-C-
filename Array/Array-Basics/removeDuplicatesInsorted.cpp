#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;



// +++++++++++++++++Bruteforce+++++++++

// int removeDuplicates(vector<int>&nums){

//    unordered_set <int>seen;
//    int index=0;

//    for (int num: nums)
//    {
//       if (seen.find(num)==seen.end())
//       {
//         seen.insert(num);

//         nums[index]=num;

//         index++;
    
//     }
      
//    }

//    return index;
   
    
// }


// ++++++++++++++++++Optimal approach


int removeDuplicates(vector<int>&nums){


    if (nums.empty())
    {
       return 0;
    }


    //pointer to last postion of last unique element


    int i=0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[i]!=nums[j])
        {
           i++;

           nums[i]=nums[j];
        }
        
    }

    return i+1;
    


    
}

int main()
{

     vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

   
    int k = removeDuplicates(nums);

    cout << "k = " << k << "\nArray after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
 return 0;
}