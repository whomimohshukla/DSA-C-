#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>arr{10,20,30,40};

    arr.push_back(30);

    arr.pop_back();

    cout<<arr.size()<<endl;
    cout<<arr.capacity()<<endl;
    cout<<arr.empty()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
   



    // arr.clear();



    

    for (int i = 0; i < arr.size(); i++)
    {
       cout<<arr[i] << " ";
    }
    
 return 0;
}