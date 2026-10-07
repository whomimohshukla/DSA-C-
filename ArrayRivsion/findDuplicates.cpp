#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool containsDuplicates(vector<int> &arr)
{

    unordered_set<int> seen;

    for (int x : arr)
    {

        if (seen.count(x))
        {
            return true;
        }
        seen.insert(x);
    }

    return false;
}

int floydTutorial(vector<int> arr)
{

    while (arr[0] != arr[arr[0]])
    {
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}
int main()
{
    vector<int> arr{1, 3, 4, 2, 2};

    // bool ans = containsDuplicates(arr);

    // if (!ans)
    // {
    //     cout << "Array does not have duplicates" << endl;
    // }
    // else
    // {

    //     cout << "Array has duplicates" << endl;
    // }

    int ans = floydTutorial(arr);

    cout << "ans is " << ans << endl;

    return 0;
}