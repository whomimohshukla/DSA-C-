#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Create loop:
    // 50 -> 30
    head->next->next->next->next->next =
        head->next->next;

    if (detectLoop(head)) {
        cout << "Loop detected";
    } else {
        cout << "No loop";
    }

    return 0;
}