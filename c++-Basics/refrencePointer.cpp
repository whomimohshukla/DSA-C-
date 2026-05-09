#include <iostream>
using namespace std;

// Pass by reference function
void swapValues(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int a = 5;

    // Reference variable
    int& ref = a;

    ref = 10;

    cout << "Value of a after reference change: " << a << endl;

    int b = 20;

    cout << "Before swap: " << endl;
    cout << "a = " << a << " b = " << b << endl;

    swapValues(a, b);

    cout << "After swap: " << endl;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}