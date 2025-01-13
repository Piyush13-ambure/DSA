//Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
//  main.cpp
//  remoove duplicates form linked list
//
//  Created by piyush ambure on 13/01/25.
//

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Solution class
class Solution {
public:
    // Function to remove duplicates from sorted linked list
    Node* removeDuplicates(Node* head) {
        // If the list is empty or has only one node, no duplicates exist
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* current = head; // Pointer to traverse the list

        // Traverse the linked list
        while (current != nullptr && current->next != nullptr) {
            // If the current node and the next node have the same data
            if (current->data == current->next->data) {
                Node* duplicate = current->next; // Duplicate node
                current->next = current->next->next; // Skip the duplicate node
                delete duplicate; // Free the memory of the duplicate node
            } else {
                // Move to the next node if no duplicate
                current = current->next;
            }
        }

        return head;
    }
};

// Helper function to append a node to the end of a linked list
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
    Node* head = nullptr;

    // Input for the linked list
    appendNode(head, 1);
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 3);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    head = solution.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

