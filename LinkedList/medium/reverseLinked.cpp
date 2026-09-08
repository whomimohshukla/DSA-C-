#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseList(Node *head)
{

    Node *prev = NULL;

    Node *curr = head;

    while (curr != NULL)
    {

        // 1. Save the next node
        Node *next = curr->next;

        // 2. Reverse the current node's pointer
        curr->next = prev;

        // 3. Move prev one step forward
        prev = curr;

        // 4. Move curr one step forward
        curr = next;
    }
    //new head
    return prev;
}
int main()
{
    Node *head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}