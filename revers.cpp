#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseString(string name)
{
    int start = 0;

    int end = name.length() - 1;

    while (start < end)
    {
        swap(name[start], name[end]);
        start++;
        end--;
    }
    return name;
}
int main()
{

    string name = "mimohshukla";

    cout << reverseString(name) << endl;

    return 0;
}