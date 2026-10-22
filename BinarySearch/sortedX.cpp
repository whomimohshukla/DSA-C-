// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /*
//     Returns the index of x in the sorted array,
//     or returns -1 if x is not present.
//     */
//     int searchInSortedArray(vector<int>& arr, int x) {
//         // Left boundary of the current search range.
//         int low = 0;

//         // Right boundary of the current search range.
//         int high = (int)arr.size() - 1;

//         // Keep searching while a valid range still exists.
//         while (low <= high) {
//             // Calculate the middle index safely.
//             int mid = low + (high - low) / 2;

//             // If the middle value matches x, the answer is found.
//             if (arr[mid] == x) {
//                 return mid;
//             }

//             // If x is larger, search only in the right half.
//             if (arr[mid] < x) {
//                 low = mid + 1;
//             } else {
//                 // If x is smaller, search only in the left half.
//                 high = mid - 1;
//             }
//         }

//         return -1;
//     }
// };

// // Driver code starts
// int main() {
//     vector<int> arr = {2, 4, 7, 10, 14, 19};
//     int x = 10;

//     Solution obj;
//     cout << obj.searchInSortedArray(arr, x) << endl;

//     return 0;
// }