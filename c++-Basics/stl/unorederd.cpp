#include <iostream>
#include <unordered_set>
using namespace std;

/*
==================================================
                unordered_set
==================================================

Definition:
-----------
unordered_set is a container that stores UNIQUE
elements using a HASH TABLE.

Properties:
-----------
1. Stores unique values only.
2. Does not maintain insertion order.
3. Fast insertion, deletion, and searching.
4. Average Time Complexity:
   - insert() : O(1)
   - find()   : O(1)
   - erase()  : O(1)
5. Worst Case:
   - O(n) due to hash collisions.

Syntax:
--------
unordered_set<int> s;

==================================================
*/

int main()
{
    // Creating an unordered_set
    unordered_set<int> s;

    cout << "===== INSERT =====\n";

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(10); // Duplicate (ignored)

    cout << "Elements:\n";
    for (int x : s)
    {
        cout << x << " ";
    }

    cout << "\n\n";

    /*
    Output may be:
    30 10 20

    OR

    20 30 10

    Order is NOT guaranteed.
    */

    cout << "===== SIZE =====\n";

    cout << "Size: " << s.size() << "\n\n";

    /*
    Duplicate 10 was ignored.

    Elements:
    10,20,30

    Size = 3
    */

    cout << "===== FIND =====\n";

    if (s.find(20) != s.end())
    {
        cout << "20 Found\n";
    }
    else
    {
        cout << "20 Not Found\n";
    }

    cout << "\n";

    /*
    find() returns iterator.

    If element exists:
        iterator != s.end()

    If element doesn't exist:
        iterator == s.end()
    */

    cout << "===== COUNT =====\n";

    cout << "Count of 30: "
         << s.count(30) << "\n";

    cout << "Count of 100: "
         << s.count(100) << "\n\n";

    /*
    count() returns:
        1 -> Present
        0 -> Not Present
    */

    cout << "===== ERASE =====\n";

    s.erase(20);

    cout << "After removing 20:\n";

    for (int x : s)
    {
        cout << x << " ";
    }

    cout << "\n\n";

    cout << "===== EMPTY =====\n";

    if (s.empty())
    {
        cout << "Set is empty\n";
    }
    else
    {
        cout << "Set is NOT empty\n";
    }

    cout << "\n\n";

    cout << "===== CLEAR =====\n";

    s.clear();

    cout << "Size after clear(): "
         << s.size() << "\n";

    cout << "\n";

    /*
    clear() removes all elements.
    */

    cout << "===== DRY RUN EXAMPLE =====\n";

    unordered_set<int> seen;

    int arr[] = {1, 2, 2, 3, 4, 4, 5};

    cout << "Array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << "\nUnique Elements: ";

    for (int x : arr)
    {
        if (seen.find(x) == seen.end())
        {
            seen.insert(x);
            cout << x << " ";
        }
    }

    cout << "\n\n";

    /*
    Dry Run:

    seen = {}

    x = 1
    not found
    insert(1)

    seen = {1}

    x = 2
    not found
    insert(2)

    seen = {1,2}

    x = 2
    already present
    skip

    x = 3
    insert(3)

    seen = {1,2,3}

    x = 4
    insert(4)

    seen = {1,2,3,4}

    x = 4
    skip

    x = 5
    insert(5)

    Final:
    {1,2,3,4,5}
    */

    return 0;
}

/*
==================================================
        set vs unordered_set
==================================================

set<int> s;

Internally:
------------
Red Black Tree

Ordered:
---------
Yes

Time Complexity:
----------------
Insert : O(log n)
Find   : O(log n)
Erase  : O(log n)

Example:
---------
1 2 3 4 5

==================================================

unordered_set<int> s;

Internally:
------------
Hash Table

Ordered:
---------
No

Time Complexity:
----------------
Insert : O(1)
Find   : O(1)
Erase  : O(1)

Example:
---------
3 1 5 2 4

(Order not fixed)

==================================================

Interview Questions:
--------------------

Q1: Why use unordered_set?

Answer:
Fast searching, insertion and deletion.

Q2: Can unordered_set store duplicates?

Answer:
No.

Q3: Does unordered_set maintain order?

Answer:
No.

Q4: Internal Data Structure?

Answer:
Hash Table.

Q5: Time Complexity?

Answer:
Average O(1)

Q6: Difference between set and unordered_set?

Answer:
set -> ordered, tree based
unordered_set -> unordered, hash based

==================================================
*/