#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};


Node* insertAtEnd(Node* head, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


void display(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main() {

    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;


    cout << "Before insertion: ";
    display(head);


    head = insertAtEnd(head, 40);


    cout << "After insertion: ";
    display(head);


    return 0;
}