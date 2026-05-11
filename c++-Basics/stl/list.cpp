#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Creating list
    list<int> l;

    // Insert elements
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    l.push_front(5);

    cout << "Initial List: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // First and last element
    cout << "Front Element: " << l.front() << endl;
    cout << "Back Element: " << l.back() << endl;

    // Remove elements
    l.pop_front();
    l.pop_back();

    cout << "After pop operations: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // Insert using iterator
    auto it = l.begin();

    l.insert(it, 100);

    cout << "After inserting 100 at beginning: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // Remove specific value
    l.remove(20);

    cout << "After removing 20: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // Reverse list
    l.reverse();

    cout << "Reversed List: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // Sort list
    l.push_back(2);
    l.push_back(50);
    l.push_back(1);

    l.sort();

    cout << "Sorted List: ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    // Size of list
    cout << "Size of List: " << l.size() << endl;

    // Check empty
    if (l.empty())
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "List is Not Empty" << endl;
    }

    return 0;
}