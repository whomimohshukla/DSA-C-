#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {
                    result += c; 
                }
                balance++;
            } else {
                balance--;
                if (balance > 0) {
                    result += c; 
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "(()())(())";
    cout << "Input:  " << s1 << endl;
    cout << "Output: " << solution.removeOuterParentheses(s1) << "\n" << endl;

    // Test Case 2
    string s2 = "(()())(())(()(()))";
    cout << "Input:  " << s2 << endl;
    cout << "Output: " << solution.removeOuterParentheses(s2) << "\n" << endl;
    
    // Test Case 3
    string s3 = "()()";
    cout << "Input:  " << s3 << endl;
    cout << "Output: " << solution.removeOuterParentheses(s3) << "\n" << endl;

    return 0;
}