/*Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.*/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Reverse the linked list and return new head
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle of the list
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverse(slow->next);

        // Step 3: Compare both halves
        Node* firstHalf = head;
        Node* temp = secondHalf;
        bool result = true;
        while (temp) {
            if (firstHalf->data != temp->data) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Step 4 (Optional): Restore the list
        slow->next = reverse(secondHalf);

        return result;
    }
};

// Utility function to insert node at end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

// Utility function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Example 1
    int arr1[] = {1, 2, 1, 1, 2, 1};
    for (int val : arr1)
        insert(head, val);

    cout << "Input: ";
    printList(head);
    Solution sol;
    cout << "Output: " << (sol.isPalindrome(head) ? "true" : "false") << endl;

    // Example 2
    head = NULL;
    int arr2[] = {1, 2, 3, 4};
    for (int val : arr2)
        insert(head, val);

    cout << "Input: ";
    printList(head);
    cout << "Output: " << (sol.isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
