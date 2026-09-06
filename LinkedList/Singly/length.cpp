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

int lengthOfLinkedList(Node *head)
{

    int count = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        count++;

        temp = temp->next;
    }
    return count;
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
    head->next->next->next = new Node(40); // Display linked list cout << "Linked List: "; display(head); // Find length
    int length = lengthOfLinkedList(head);
    cout << "Length of Linked List: " << length << endl;
    return 0;
}