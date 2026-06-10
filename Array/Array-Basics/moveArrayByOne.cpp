#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void moveByOne(vector<int>&arr){


    int n=arr.size();

    int temp[n];

    for (int i = 1; i <n; i++)
    {
        temp[i-1]=arr[i];
    }

    temp[n-1]=arr[0];

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";  // Print each element of the rotated array
    }
    cout << endl;
    
}
int main()
{
    vector<int>arr{1, 2, 3, 4, 5};

    moveByOne(arr);

 return 0;
}