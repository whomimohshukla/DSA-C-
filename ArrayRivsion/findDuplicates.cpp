#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool containsDuplicates(vector<int> &arr)
{

    unordered_set<int>seen;

   for(int x:arr){

    if(seen.count(x)){
        return true;
    }
    seen.insert(x);

   }

   return false;
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,7};

    bool ans = containsDuplicates(arr);

    if (!ans)
    {
        cout << "Array does not have duplicates" << endl;
    }
    else
    {

        cout << "Array has duplicates" << endl;
    }

    return 0;
}