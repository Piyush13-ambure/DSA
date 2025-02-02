//Given Pointer/Reference to the head of a doubly linked list, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

//Note: Return the head of the sorted non-decreasing doubly linked list. The driver code will print it forward and backward in both directions.

#include <bits/stdc++.h>
using namespace std;

// Node structure for a doubly linked list
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class Solution {
public:
    // Function to find the middle of the DLL
    DLLNode* getMiddle(DLLNode* head) {
        if (!head) return head;
        DLLNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted doubly linked lists
    DLLNode* merge(DLLNode* first, DLLNode* second) {
        if (!first) return second;
        if (!second) return first;

        // Choose the smaller value node and recursively merge
        if (first->data <= second->data) {
            first->next = merge(first->next, second);
            if (first->next) first->next->prev = first;
            first->prev = NULL;
            return first;
        } else {
            second->next = merge(first, second->next);
            if (second->next) second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }

    // Function to perform Merge Sort on a doubly linked list
    DLLNode* sortDoubly(DLLNode* head) {
        if (!head || !head->next) return head; // Base case: empty or single node

        // Find the middle node
        DLLNode* middle = getMiddle(head);
        DLLNode* secondHalf = middle->next;
        middle->next = NULL;
        if (secondHalf) secondHalf->prev = NULL;

        // Recursively sort both halves
        DLLNode* left = sortDoubly(head);
        DLLNode* right = sortDoubly(secondHalf);

        // Merge sorted halves
        return merge(left, right);
    }
};

// Utility functions for testing
void printForward(DLLNode* head) {
    DLLNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(DLLNode* head) {
    if (!head) return;
    // Move to the last node
    while (head->next) head = head->next;
    // Print in reverse
    while (head) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

// Driver code
int main() {
    DLLNode* head = new DLLNode(4);
    head->next = new DLLNode(2);
    head->next->prev = head;
    head->next->next = new DLLNode(8);
    head->next->next->prev = head->next;
    head->next->next->next = new DLLNode(5);
    head->next->next->next->prev = head->next->next;
    
    Solution sol;
    head = sol.sortDoubly(head);

    cout << "Sorted Doubly Linked List (Forward): ";
    printForward(head);
    cout << "Sorted Doubly Linked List (Backward): ";
    printBackward(head);

    return 0;
}
