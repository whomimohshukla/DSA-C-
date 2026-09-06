#include <iostream>
#include <vector>
#include <algorithm>
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

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *insertHead(Node *head, int value)
{

    Node *newNode = new Node(value);

    newNode->next = head;

    head = newNode;

    return head;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

int main()
{
    Node *head = new Node(10);

    head->next = new Node(20);

    head->next->next = new Node(30);

    head = insertHead(head, 5);

    print(head);

    return 0;
}