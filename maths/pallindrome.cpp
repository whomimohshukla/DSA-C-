#include <iostream>
using namespace std;

bool validPalindrome(int number)
{
    int reverseNum = 0;
    int original = number;

    while (number > 0)
    {
        int lastDigit = number % 10;

        reverseNum = reverseNum * 10 + lastDigit;

        number = number / 10;
    }

    return reverseNum == original;
}

int main()
{
    int number = 121;

    if (validPalindrome(number))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}