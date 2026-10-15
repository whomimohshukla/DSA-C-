#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Move left pointer forward if not alphanumeric
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }

        // Move right pointer backward if not alphanumeric
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Compare characters in lowercase
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        // Move both pointers inward
        left++;
        right--;
    }

    return true;
}
int main()
{
    string str = "A man, a plan!";

    
    if (!isPalindrome(str))
    {
        cout << "string is not pallindrome" << endl;
    }
    else
    {
        cout << "string is pallindrome" << endl;
    }
    return 0;
}