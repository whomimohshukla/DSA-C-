#include <iostream>
#include <vector>
using namespace std;

int FindUniqueElement(const vector<int>& arr) {
    int ans = 0;
    for (int x : arr) ans ^= x;
    return ans;
}

int main() {
    vector<int> arr{2, 3, 5, 4, 5, 3, 4};   // valid pattern for XOR
    cout << "Unique element of array: " << FindUniqueElement(arr) << endl;
    return 0;
}