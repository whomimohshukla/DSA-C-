
#include <bits/stdc++.h>
using namespace std;


// ===============================
// Node Class
// ===============================
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// ===============================
// Display Linked List
// ===============================
void display(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// ===============================
// 1. INSERT AT BEGINNING
// ===============================
Node* insertAtBeginning(Node* head, int value) {

    // Create new node
    Node* newNode = new Node(value);

    // New node points to current head
    newNode->next = head;

    // Make new node the new head
    head = newNode;

    return head;
}


// ===============================
// 2. INSERT AT END
// ===============================
Node* insertAtEnd(Node* head, int value) {

    // Create new node
    Node* newNode = new Node(value);

    // If list is empty
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to last node
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Last node points to new node
    temp->next = newNode;

    return head;
}


// ===============================
// 3. INSERT AT POSITION
// Position starts from 1
// ===============================
Node* insertAtPosition(Node* head, int value, int position) {

    // Invalid position
    if (position <= 0) {
        cout << "Invalid position\n";
        return head;
    }

    // Position 1 means beginning
    if (position == 1) {
        return insertAtBeginning(head, value);
    }

    Node* temp = head;

    // Move to node BEFORE required position
    for (int i = 1; i < position - 1; i++) {

        if (temp == nullptr) {
            cout << "Position does not exist\n";
            return head;
        }

        temp = temp->next;
    }

    // If position is beyond list
    if (temp == nullptr) {
        cout << "Position does not exist\n";
        return head;
    }

    // Create new node
    Node* newNode = new Node(value);

    // Connect new node to next node
    newNode->next = temp->next;

    // Connect previous node to new node
    temp->next = newNode;

    return head;
}


// ===============================
// 4. INSERT AFTER A GIVEN VALUE
// ===============================
Node* insertAfterValue(Node* head, int target, int value) {

    Node* temp = head;

    // Search target
    while (temp != nullptr) {

        if (temp->data == target) {

            Node* newNode = new Node(value);

            // New node points to target's next
            newNode->next = temp->next;

            // Target points to new node
            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }

    cout << "Target value not found\n";

    return head;
}


// ===============================
// 5. INSERT BEFORE A GIVEN VALUE
// ===============================
Node* insertBeforeValue(Node* head, int target, int value) {

    // Empty list
    if (head == nullptr) {
        cout << "List is empty\n";
        return head;
    }

    // If target is first node
    if (head->data == target) {
        return insertAtBeginning(head, value);
    }

    Node* temp = head;

    // Find node BEFORE target
    while (temp->next != nullptr) {

        if (temp->next->data == target) {

            Node* newNode = new Node(value);

            // New node points to target
            newNode->next = temp->next;

            // Previous node points to new node
            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }

    cout << "Target value not found\n";

    return head;
}


// ===============================
// MAIN
// ===============================
int main() {

    // Create initial linked list
    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);


    cout << "Initial List:\n";
    display(head);


    // ===========================
    // Insert at Beginning
    // ===========================
    head = insertAtBeginning(head, 5);

    cout << "\nAfter inserting 5 at beginning:\n";
    display(head);


    // ===========================
    // Insert at End
    // ===========================
    head = insertAtEnd(head, 50);

    cout << "\nAfter inserting 50 at end:\n";
    display(head);


    // ===========================
    // Insert at Position
    // ===========================
    head = insertAtPosition(head, 25, 4);

    cout << "\nAfter inserting 25 at position 4:\n";
    display(head);


    // ===========================
    // Insert After Value
    // ===========================
    head = insertAfterValue(head, 30, 35);

    cout << "\nAfter inserting 35 after 30:\n";
    display(head);


    // ===========================
    // Insert Before Value
    // ===========================
    head = insertBeforeValue(head, 40, 37);

    cout << "\nAfter inserting 37 before 40:\n";
    display(head);


    return 0;
}
