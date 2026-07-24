#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int maxSubArray(vector<int>&arr){
    long long maxi=LLONG_MIN;
    long long sum=0;

    for (int i = 0; i < arr.size(); i++)
    {
       sum+=arr[i];

       if (sum>maxi)
       {
        maxi=sum;
        
       }

       if (sum<0)
       {
         sum=0;
       }
       
       
    }

    return maxi;
    
}
int main()
{ 
    vector<int> arr = { 2,3,-7,4,7,-4};

    // Create an instance of Solution class

    int maxSum = maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}