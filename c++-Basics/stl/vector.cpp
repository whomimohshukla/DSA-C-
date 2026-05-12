#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;

    // insert
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // print
    for(int x : v)
        cout << x << " ";

    cout << endl;

    // size
    cout << v.size() << endl;

    // capacity
    cout << v.capacity() << endl;

    // access
    cout << v[0] << endl;
    cout << v.at(1) << endl;

    // first element
    cout << v.front() << endl;

    // last element
    cout << v.back() << endl;

    // remove last
    v.pop_back();

    // insert at index
    v.insert(v.begin()+1,100);

    // erase
    v.erase(v.begin());

    // clear
    v.clear();

    return 0;
}