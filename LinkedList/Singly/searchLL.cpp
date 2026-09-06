
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

bool searchInLinkedList(Node *head, int target)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    display(head);

    int target = 30;

    if (searchInLinkedList(head, target))
    {
        cout << target << " is found" << endl;
    }
    else
    {
        cout << target << " is not found" << endl;
    }

    return 0;
}
