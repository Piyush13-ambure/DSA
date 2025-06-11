/*Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Your task:
You don't have to read input or print anything. Your task is to complete the function findPrefixes() which takes the array of strings and it's size N as input and returns a list of shortest unique prefix for each word*/


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverseBetween(int a, int b, Node* head) {
        if (!head || a == b) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;

        // Step 1: Move `prev` to the node just before position `a`
        for (int i = 1; i < a; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse the sublist from `a` to `b`
        Node* curr = prev->next; // `curr` is the first node to be reversed
        Node* next = nullptr;
        for (int i = 0; i < b - a; i++) {
            next = curr->next; // Store next node
            curr->next = next->next; // Reverse the link
            next->next = prev->next; // Move `next` to the front of the reversed sublist
            prev->next = next; // Connect `prev` to the new front
        }

        // Step 3: Return the new head of the list
        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    // Create a linked list: 1->7->5->3->9->8->10->2->2->5->NULL
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(5);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next->next->next = new Node(5);

    Solution sol;
    int a = 1, b = 8;
    Node* newHead = sol.reverseBetween(a, b, head);
    printList(newHead); // Expected output: 2 10 8 9 3 5 7 1 2 5

    // Clean up memory (not shown for brevity)
    return 0;
}
