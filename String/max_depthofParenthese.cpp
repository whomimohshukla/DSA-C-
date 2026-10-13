#include <iostream>
#include <string>
#include <algorithm> // For std::max

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int current_depth = 0;
        int max_depth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                current_depth++;
                // Update max_depth if current_depth is a new high
                max_depth = max(max_depth, current_depth);
            }
            else if (c == ')')
            {
                current_depth--;
            }
        }

        return max_depth;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << solution.maxDepth(s1) << " (Expected: 3)\n"
         << endl;

    // Test Case 2
    string s2 = "(1)+((2))+(((3)))";
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << solution.maxDepth(s2) << " (Expected: 3)\n"
         << endl;

    // Test Case 3
    string s3 = "()(())((()()))";
    cout << "Input:  " << s3 << endl;
    cout << "Output: " << solution.maxDepth(s3) << " (Expected: 3)\n"
         << endl;

    return 0;
}