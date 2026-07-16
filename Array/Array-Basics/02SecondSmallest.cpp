#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int secondSmallest(vector<int>&arr){


    if(arr.size()<2){
        return -1;
    }

    int small=INT_MAX;

    int second_small=INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        
        if (arr[i]<small)
        {
           second_small=small;
           small=arr[i];
        }

        else if (arr[i]<second_small && arr[i]!=small)
        {
            second_small=arr[i];
        }
        
        
    }

    return second_small;
    
}

int main()
{

    vector<int>arr{1,2,3,7,7,5};

    cout<<"Second smalles element is:"<<secondSmallest(arr);
 return 0;
}



// We will need four variables: small, second_small, large, and second_large. Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.
// Second Smallest Algorithm:
// If the current element is smaller than 'small', update the values of second_small and small.
// Else if the current element is smaller than 'second_small', update the value of second_small.
// After traversing the array, the second smallest element will be stored in the variable second_small.
// Second Largest Algorithm:
// If the current element is larger than 'large', update the values of second_large and large.
// Else if the current element is larger than 'second_large', update the value of second_large.
// After traversing the array, the second largest element will be stored in the variable second_large.



