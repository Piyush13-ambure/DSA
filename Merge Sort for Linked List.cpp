//Given a pointer/reference to the head of the linked list, the task is to sort the given linked list using Merge Sort.
//Note: If the length of the linked list is odd, then the extra node should go into the first list while splitting.


#include <iostream>
using namespace std;

// Definition for a Node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    // Function to find the middle node of the linked list
    Node* getMiddle(Node* head) {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head->next; // Ensures odd-length lists split correctly

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to sort the given linked list using Merge Sort
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head; // Base case for recursion

        // Find the middle of the linked list
        Node* middle = getMiddle(head);
        Node* secondHalf = middle->next;
        middle->next = nullptr; // Split the list into two halves

        // Recursively sort both halves
        Node* leftSorted = mergeSort(head);
        Node* rightSorted = mergeSort(secondHalf);

        // Merge the sorted halves
        return merge(leftSorted, rightSorted);
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Main function to test the solution
int main() {
    Node* head = nullptr;
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    insert(head, 4);
    insert(head, 1);

    cout << "Original Linked List: ";
    printList(head);

    Solution sol;
    head = sol.mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
