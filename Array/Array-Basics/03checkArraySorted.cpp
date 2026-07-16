#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkArraySorted(vector<int>&arr){


    // if we put i=0 insted of i=1 it will be arr[-1] and which is out of bound
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i]<arr[i-1])
        {
            return false;
        }

        
    }
    return true;
    
}
int main()
{
    vector<int>arr{1,2,3,4,5};

    if (!checkArraySorted(arr))
    {
       cout<<"array is not sorted"<<endl;
    }
    else{

        cout<<"array is sorted "<<endl;
    }
    
 return 0;
}




// | i | arr[i-1] | arr[i] | Condition `arr[i] < arr[i-1]` |
// | - | -------- | ------ | ----------------------------- |
// | 1 | 1        | 2      | false                         |
// | 2 | 2        | 3      | false                         |
// | 3 | 3        | 4      | false                         |
// | 4 | 4        | 5      | false                         |
