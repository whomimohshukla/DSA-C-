#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countOnes(vector<int> &arr)
{

    int currentCount = 0;

    int maxiMumCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {

            currentCount++;

            maxiMumCount = max(currentCount, maxiMumCount);
        }
        else
        {
            currentCount = 0;
        }
    }
    return maxiMumCount;
}
int main()
{
    vector<int> arr{1, 1, 0, 1, 1, 1};
    cout << countOnes(arr) << endl;
    return 0;
}