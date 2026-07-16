#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestElement(vector<int>&arr){
     
    // initilize the variable to store the maximum element
    int maxi=arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i]>maxi)
        {
            maxi=arr[i];
        }
        
    }

    return maxi;
    
}
int main()
{
    vector<int>arr{2,5,1,3,0};

    cout<<"maximum element is :"<<largestElement(arr);
 return 0;
}