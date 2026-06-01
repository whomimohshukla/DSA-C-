#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxElement(vector<int>&arr){

    int max=arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
       if (arr[max]<arr[i])
       {
        max=arr[i];
       }
       
    }

    return max;
    
}
void printVector(const vector<int> &arr)
{
    for (int num : arr)
    cout << num << " ";
    cout << endl;
}
int main()
{

    vector<int> arr{1, 3, 2, 3, 10, 22};


   int ans=maxElement(arr);

   cout<<ans;

    // printVector(arr);
}