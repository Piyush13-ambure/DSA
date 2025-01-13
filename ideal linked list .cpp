//
//  main.cpp
//  ideal linked list
//
//  Created by piyush ambure on 13/01/25.
//

#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Solution class containing the function to check identical linked lists
class Solution {
public:
    // Function to check if two linked lists are identical
    bool areIdentical(struct Node* head1, struct Node* head2) {
        // Traverse both linked lists
        while (head1 != nullptr && head2 != nullptr) {
            // Compare the data in the current nodes
            if (head1->data != head2->data) {
                return false;  // Data mismatch
            }
            // Move to the next nodes in both lists
            head1 = head1->next;
            head2 = head2->next;
        }

        // Check if both lists have been completely traversed
        return (head1 == nullptr && head2 == nullptr);
    }
};

// Helper function to add a new node at the end of a linked list
void appendNode(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Input for the first linked list
    appendNode(head1, 1);
    appendNode(head1, 2);
    appendNode(head1, 3);

    // Input for the second linked list
    appendNode(head2, 1);
    appendNode(head2, 2);
    appendNode(head2, 3);

    // Print the linked lists
    cout << "Linked List 1: ";
    printList(head1);
    cout << "Linked List 2: ";
    printList(head2);

    // Check if the linked lists are identical
    Solution solution;
    if (solution.areIdentical(head1, head2)) {
        cout << "The linked lists are identical." << endl;
    } else {
        cout << "The linked lists are not identical." << endl;
    }

    return 0;
}
