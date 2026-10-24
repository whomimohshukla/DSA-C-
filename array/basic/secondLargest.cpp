#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// // bruteForce nlogn+n
// int secondLargest(vector<int> &arr)

// {

//     // sort array

//     sort(arr.begin(), arr.end());

//     int n = arr.size();
//     int maxi = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (arr[i] > maxi)
//         {
//             maxi = arr[i];
//         }
//     }

//     return maxi;
// }

// int secondLargest(vector<int> &arr)
// {

//     int largest = INT_MIN;

//     // one pass
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] > largest)
//         {
//             largest = arr[i];
//         }
//     }

//     // second pass

//     int secondLarge = INT_MIN;

//     for (int i = 0; i < arr.size(); i++)
//     {

//         if (arr[i] > secondLarge && arr[i] != largest)
//         {
//             secondLarge = arr[i];
//         }
//     }

//     return secondLarge;
// }

int secondLargest(vector<int> &arr)
{
    int largest = arr[0];

    int secondLargest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {

            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{

    vector<int> arr{2, 3, 4, 5, 6};

    int target = 3;

    int ans = secondLargest(arr);

    cout << "value find at:" << ans << endl;

    return 0;
}