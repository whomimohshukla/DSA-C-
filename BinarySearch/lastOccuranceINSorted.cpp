#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lastOccurance(vector<int>&arr,int key){



    int start=0;

    int end=arr.size()-1;

    int res=-1;


    while (start<end)
    {
        int mid=start+(end-start)/2;


        if (arr[mid]==key)
        {
            res=mid;

           start = mid + 1;    // Search right side
           
        }

        

       else  if (arr[mid]>key)
        {
           end=mid-1;
        }
        else{
            start=mid+1;
        }
        
    }

    return res;
    
}
int main()
{


     vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
     int key=13;


     cout << lastOccurance(arr,key) << "\n";


   
 return 0;
}