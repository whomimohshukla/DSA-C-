#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int peakElement(vector<int>&arr){


    int start=0;

    int end=arr.size()-1;


    while (start<end)
    {
        int mid=start+(end-start)/2;

        if (arr[mid]>arr[mid+1])
        {
           end=mid;
        }
        else{
            start=mid+1;
        }
        
    }

    return start;
    
}
int main()
{


    vector<int>arr{1,2,3,4,5,6,7,8,5,1};

    int index=peakElement(arr);


    cout<<"Peak element is :"<<arr[index]<<"  at index :"<<index<<endl;

 return 0;
}