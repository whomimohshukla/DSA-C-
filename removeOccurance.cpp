#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string removeOccurance(string str, string part)
{

    int pos = str.find(part);

    while (pos != string::npos)
    {
        str.erase(pos, part.length());

        pos = str.find(part);
    }
    return str;
}
int main()
{

    string name = "daabcbaabcbc";

    string part = "abc";

    cout << removeOccurance(name, part) << endl;

    return 0;
}