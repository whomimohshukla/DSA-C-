#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


// Print linked list
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Method 1: Count length
Node* middleByLength(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    // Find length
    int length = 0;
    Node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Move to middle
    int middle = length / 2;

    temp = head;

    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }

    return temp;
}


// Method 2: Slow and Fast pointer
// Returns SECOND middle for even length
Node* middleSlowFast(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// Method 3: Slow and Fast pointer
// Returns FIRST middle for even length
Node* firstMiddle(Node* head) {

    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main() {

    // Create:
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);


    cout << "Linked List: ";
    printList(head);


    // Second middle
    Node* middle = middleSlowFast(head);

    cout << "Second Middle: "
         << middle->data << endl;


    // First middle
    Node* first = firstMiddle(head);

    cout << "First Middle: "
         << first->data << endl;


    return 0;
}
