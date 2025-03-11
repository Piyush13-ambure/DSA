/*You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.*/


#include <iostream>
using namespace std;

/* Linked List Node */
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
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Moves one step
            fast = fast->next->next;    // Moves two steps

            if (slow == fast) {
                return true;  // Loop detected
            }
        }
        return false; // No loop found
    }
};

// Helper function to create a loop in the linked list
void createLoop(Node* head, int pos) {
    if (pos == 0) return; // No loop

    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;

    // Traverse the list to find the node at position `pos`
    while (temp->next != NULL) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // Connect the last node to the loopNode
    temp->next = loopNode;
}

// Helper function to print the linked list (for debugging)
void printList(Node* head) {
    Node* temp = head;
    int count = 10; // Print only 10 elements to avoid infinite loops
    while (temp != NULL && count--) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Creating linked list: 1 -> 3 -> 4
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(4);
    createLoop(head1, 2); // Creating a loop at position 2

    Solution sol;
    cout << (sol.detectLoop(head1) ? "true" : "false") << endl; // Output: true

    // Creating linked list: 1 -> 8 -> 3 -> 4
    Node* head2 = new Node(1);
    head2->next = new Node(8);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    createLoop(head2, 0); // No loop

    cout << (sol.detectLoop(head2) ? "true" : "false") << endl; // Output: false

    // Creating linked list: 1 -> 2 -> 3 -> 4
    Node* head3 = new Node(1);
    head3->next = new Node(2);
    head3->next->next = new Node(3);
    head3->next->next->next = new Node(4);
    createLoop(head3, 1); // Creating a loop at position 1

    cout << (sol.detectLoop(head3) ? "true" : "false") << endl; // Output: true

    return 0;
}
