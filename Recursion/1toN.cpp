#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to print numbers from current to n
    void printNumbers(int current, int n) {
        // Base case: if current exceeds n, stop recursion
        if (current > n)
            return;

        // Print current number
        cout << current << " ";

        // Recursive call with next number
        printNumbers(current + 1, n);
    }
};

int main() {
    Solution sol;
    int n = 10;

    sol.printNumbers(1, n);
    cout << "\n";

    return 0;
}
