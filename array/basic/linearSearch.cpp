#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{

    vector<int> arr{2, 3, 4, 5, 6};

    int target = 3;

    int ans = linearSearch(arr, target);

    cout << "value find at:" << ans << endl;

    return 0;
}