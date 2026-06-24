#include <iostream>
#include <vector>
using namespace std;

int findElementUsingIterative(vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;   // return index
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1; // element not found
}

int main() {
    vector<int> arr{3, 4, 6, 7, 9, 12, 16, 17};

    int key = 7;

    int ans = findElementUsingIterative(arr, key);

    if (ans != -1)
        cout << "Element found at index: " << ans << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}