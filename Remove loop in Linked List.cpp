/*Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

Custom Input format:

A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.*/



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

class Solution {
public:
    // Function to detect and remove the loop in the linked list.
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node *slow = head, *fast = head;
        
        // Step 1: Detect loop using Floyd's Cycle Detection Algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // Cycle detected
                break;
            }
        }

        // No cycle detected
        if (slow != fast) return;

        // Step 2: Find the starting node of the cycle
        slow = head;
        Node* prev = NULL; // To track the last node in the cycle
        while (slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Remove the loop
        prev->next = NULL;
    }
};

// Utility function to create a linked list from a vector and add a loop
Node* createLinkedListWithLoop(vector<int> values, int pos) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* temp = head;
    Node* loopNode = NULL;

    for (int i = 1; i < values.size(); i++) {
        temp->next = new Node(values[i]);
        temp = temp->next;
        if (i == pos - 1) {
            loopNode = temp;
        }
    }

    // If pos is not 0, create the loop
    if (pos > 0) {
        temp->next = loopNode;
    }

    return head;
}

// Utility function to check if the linked list contains a loop
bool hasLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Function to print the linked list
void printList(Node* head) {
    unordered_set<Node*> visited;
    while (head) {
        if (visited.find(head) != visited.end()) {
            cout << "LOOP DETECTED!" << endl;
            return;
        }
        cout << head->data << " -> ";
        visited.insert(head);
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the removeLoop function
int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 4}, 2},   // Test case with a loop
        {{1, 8, 3, 4}, 0}, // No loop
        {{1, 2, 3, 4}, 1}  // Loop exists
    };

    Solution sol;

    for (auto testCase : testCases) {
        Node* head = createLinkedListWithLoop(testCase.first, testCase.second);

        cout << "Before removing loop: " << (hasLoop(head) ? "Loop exists" : "No loop") << endl;
        sol.removeLoop(head);
        cout << "After removing loop: " << (hasLoop(head) ? "Loop exists" : "No loop") << endl;
        printList(head);
        cout << "---------------------------------" << endl;
    }

    return 0;
}
