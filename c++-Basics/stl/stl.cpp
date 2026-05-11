/*
===========================================================
        C++ STL NOTES + ALL OPERATIONS + COMPLEXITIES
===========================================================

AUTHOR : Mimoh Shukla
LANGUAGE : C++
TOPIC : STL (Standard Template Library)

-----------------------------------------------------------
WHAT IS STL?
-----------------------------------------------------------
STL = Standard Template Library

It provides:
1. Containers      -> store data
2. Algorithms      -> sorting, searching, etc.
3. Iterators       -> pointer-like objects
4. Functors        -> objects behaving like functions

-----------------------------------------------------------
MOST IMPORTANT STL CONTAINERS FOR DSA
-----------------------------------------------------------

1. vector
2. pair
3. list
4. deque
5. stack
6. queue
7. priority_queue
8. set
9. multiset
10. unordered_set
11. map
12. multimap
13. unordered_map

===========================================================
                    HEADER FILES
===========================================================
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
===========================================================
                    VECTOR
===========================================================

Dynamic Array

TIME COMPLEXITY:
------------------------------------------------
push_back()        -> O(1) amortized
pop_back()         -> O(1)
insert()           -> O(n)
erase()            -> O(n)
access by index    -> O(1)
size()             -> O(1)
sort()             -> O(n log n)

WHY USE VECTOR?
------------------------------------------------
- Dynamic size
- Fast random access
- Most used STL container
*/

void vectorNotes()
{
    vector<int> v;

    // insert elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // print vector
    cout << "Vector Elements: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // access elements
    cout << "First Element: " << v[0] << endl;

    // size
    cout << "Size: " << v.size() << endl;

    // remove last element
    v.pop_back();

    // insert at position
    v.insert(v.begin() + 1, 100);

    // erase element
    v.erase(v.begin());

    // sort vector
    sort(v.begin(), v.end());

    cout << "After Operations: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

/*
===========================================================
                    LIST
===========================================================

Doubly Linked List

TIME COMPLEXITY:
------------------------------------------------
push_front()       -> O(1)
push_back()        -> O(1)
pop_front()        -> O(1)
pop_back()         -> O(1)
insert()           -> O(1) if iterator known
erase()            -> O(1)
access by index    -> NOT ALLOWED

WHY USE LIST?
------------------------------------------------
- Fast insertion/deletion
- No contiguous memory needed
- Used in LRU Cache etc.
*/

void listNotes()
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);

    l.push_front(5);

    cout << "List Elements: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;

    // remove first
    l.pop_front();

    // remove last
    l.pop_back();

    l.push_back(100);
    l.push_back(200);

    // insert using iterator
    auto it = l.begin();
    l.insert(it, 50);

    cout << "After Operations: ";
    for (int x : l)
        cout << x << " ";
    cout << endl;
}

/*
===========================================================
                    DEQUE
===========================================================

Double Ended Queue

TIME COMPLEXITY:
------------------------------------------------
push_front()       -> O(1)
push_back()        -> O(1)
pop_front()        -> O(1)
pop_back()         -> O(1)
access by index    -> O(1)

WHY USE DEQUE?
------------------------------------------------
- Insertion from both ends
- Faster than vector for front insertion
*/

void dequeNotes()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);

    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After Pop: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;
}

/*
===========================================================
                    STACK
===========================================================

LIFO = Last In First Out

TIME COMPLEXITY:
------------------------------------------------
push()             -> O(1)
pop()              -> O(1)
top()              -> O(1)

USES:
------------------------------------------------
- Recursion
- Expression evaluation
- Undo operation
*/

void stackNotes()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.top() << endl;

    st.pop();

    cout << "Top After Pop: " << st.top() << endl;
}

/*
===========================================================
                    QUEUE
===========================================================

FIFO = First In First Out

TIME COMPLEXITY:
------------------------------------------------
push()             -> O(1)
pop()              -> O(1)
front()            -> O(1)

USES:
------------------------------------------------
- BFS
- Scheduling
*/

void queueNotes()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "Front After Pop: " << q.front() << endl;
}

/*
===========================================================
                PRIORITY QUEUE (HEAP)
===========================================================

Max Heap by default

TIME COMPLEXITY:
------------------------------------------------
push()             -> O(log n)
pop()              -> O(log n)
top()              -> O(1)

USES:
------------------------------------------------
- Dijkstra
- Heap Sort
- Top K problems
*/

void priorityQueueNotes()
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Max Element: " << pq.top() << endl;

    pq.pop();

    cout << "After Pop Top: " << pq.top() << endl;
}

/*
===========================================================
                        SET
===========================================================

Stores UNIQUE sorted elements

Implemented using Red Black Tree

TIME COMPLEXITY:
------------------------------------------------
insert()           -> O(log n)
erase()            -> O(log n)
find()             -> O(log n)

USES:
------------------------------------------------
- Unique elements
- Sorted data
*/

void setNotes()
{
    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(10);

    cout << "Set Elements: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // find
    if (s.find(20) != s.end())
        cout << "20 Found\n";

    s.erase(10);

    cout << "After Erase: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;
}

/*
===========================================================
                    UNORDERED SET
===========================================================

Unique elements but NOT sorted

Uses Hashing

TIME COMPLEXITY:
------------------------------------------------
insert()           -> O(1) average
erase()            -> O(1) average
find()             -> O(1) average

USES:
------------------------------------------------
- Fast searching
*/

void unorderedSetNotes()
{
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);

    cout << "Unordered Set: ";
    for (int x : us)
        cout << x << " ";
    cout << endl;
}

/*
===========================================================
                        MAP
===========================================================

Key Value Pair

Keys are UNIQUE and sorted

TIME COMPLEXITY:
------------------------------------------------
insert()           -> O(log n)
erase()            -> O(log n)
find()             -> O(log n)

USES:
------------------------------------------------
- Frequency counting
- Storing data in key-value form
*/

void mapNotes()
{
    map<string, int> mp;

    mp["mango"] = 100;
    mp["apple"] = 50;
    mp["banana"] = 40;

    cout << "Map Elements:\n";

    for (auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    // access
    cout << "Price of Apple: " << mp["apple"] << endl;

    // find
    if (mp.find("banana") != mp.end())
        cout << "Banana Found\n";

    // erase
    mp.erase("apple");

    cout << "After Erase:\n";
    for (auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}

/*
===========================================================
                UNORDERED MAP
===========================================================

Hash Table based key-value pair

NOT SORTED

TIME COMPLEXITY:
------------------------------------------------
insert()           -> O(1) average
erase()            -> O(1) average
find()             -> O(1) average

USES:
------------------------------------------------
- Frequency counting
- Fast lookup
*/

void unorderedMapNotes()
{
    unordered_map<string, int> ump;

    ump["A"] = 1;
    ump["B"] = 2;
    ump["C"] = 3;

    cout << "Unordered Map:\n";

    for (auto x : ump)
    {
        cout << x.first << " -> " << x.second << endl;
    }
}

/*
===========================================================
                    ALGORITHMS
===========================================================

Most Important STL Algorithms

sort()             -> O(n log n)
reverse()          -> O(n)
binary_search()    -> O(log n)
max_element()      -> O(n)
min_element()      -> O(n)
count()            -> O(n)

HEADER:
#include <algorithm>
*/

void algorithmNotes()
{
    vector<int> v = {4, 2, 8, 1, 9};

    // sort
    sort(v.begin(), v.end());

    cout << "Sorted Vector: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // reverse
    reverse(v.begin(), v.end());

    cout << "Reversed Vector: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // binary search
    bool found = binary_search(v.begin(), v.end(), 8);

    cout << "8 Found? " << found << endl;

    // max element
    cout << "Max Element: "
         << *max_element(v.begin(), v.end()) << endl;

    // min element
    cout << "Min Element: "
         << *min_element(v.begin(), v.end()) << endl;
}

/*
===========================================================
                    MAIN FUNCTION
===========================================================
*/

int main()
{
    cout << "\n===== VECTOR =====\n";
    vectorNotes();

    cout << "\n===== LIST =====\n";
    listNotes();

    cout << "\n===== DEQUE =====\n";
    dequeNotes();

    cout << "\n===== STACK =====\n";
    stackNotes();

    cout << "\n===== QUEUE =====\n";
    queueNotes();

    cout << "\n===== PRIORITY QUEUE =====\n";
    priorityQueueNotes();

    cout << "\n===== SET =====\n";
    setNotes();

    cout << "\n===== UNORDERED SET =====\n";
    unorderedSetNotes();

    cout << "\n===== MAP =====\n";
    mapNotes();

    cout << "\n===== UNORDERED MAP =====\n";
    unorderedMapNotes();

    cout << "\n===== ALGORITHMS =====\n";
    algorithmNotes();

    return 0;
}

/*
===========================================================
                    IMPORTANT INTERVIEW NOTES
===========================================================

VECTOR vs ARRAY
------------------------------------------------
Array:
- Fixed size
- Faster slightly

Vector:
- Dynamic size
- Easier to use

------------------------------------------------

MAP vs UNORDERED_MAP
------------------------------------------------
map:
- Sorted
- O(log n)

unordered_map:
- Not sorted
- O(1) average

------------------------------------------------

SET vs UNORDERED_SET
------------------------------------------------
set:
- Sorted unique
- O(log n)

unordered_set:
- Unsorted unique
- O(1) average

------------------------------------------------

STACK vs QUEUE
------------------------------------------------
Stack:
- LIFO

Queue:
- FIFO

===========================================================
                    END OF STL NOTES
===========================================================
*/