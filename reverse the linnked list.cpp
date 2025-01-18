//Given the head of a linked list, the task is to reverse this list and return the reversed head.#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr; // Previous node
        Node* current = head; // Current node
        Node* next = nullptr; // Next node

        while (current != nullptr) {
            // Store the next node
            next = current->next;
            // Reverse the current node's pointer
            current->next = prev;
            // Move the pointers one step forward
            prev = current;
            current = next;
        }

        // New head of the reversed list
        return prev;
    }
};

// Helper function to create a linked list from an array
Node* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function to test the Solution class
int main() {
    Solution solution;

    // Input: Create a linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    Node* head = createLinkedList(values);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    Node* reversedHead = solution.reverseList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(reversedHead);

    return 0;
}
