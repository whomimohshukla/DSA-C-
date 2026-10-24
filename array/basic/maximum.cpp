#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int linearSearch(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {

            maxi = arr[i];
        }
    }
    return maxi;
}
int main()
{

    vector<int> arr{2, 3, 4, 5, 6};

    int target = 3;

    int ans = linearSearch(arr);

    cout << "value find at:" << ans << endl;

    return 0;
}