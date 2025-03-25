/*Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.*/



#include <bits/stdc++.h>
using namespace std;

// Structure for tree and doubly linked list
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* prev = NULL; // Pointer to keep track of the previous node
    Node* head = NULL; // Head of the DLL

    // Function to convert binary tree to doubly linked list
    Node* bToDLL(Node* root) {
        if (!root) return NULL;

        // Recursively convert the left subtree
        bToDLL(root->left);

        // Process current node
        if (prev == NULL) {
            head = root; // First node of inorder traversal becomes head of DLL
        } else {
            prev->right = root; // Link previous node with current node
            root->left = prev;
        }
        prev = root; // Move previous pointer

        // Recursively convert the right subtree
        bToDLL(root->right);

        return head; // Return the head of the DLL
    }
};

// Function to print the doubly linked list in forward direction
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// Function to print the doubly linked list in reverse direction
void printReverse(Node* head) {
    Node* temp = head;
    while (temp->right) {
        temp = temp->right;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->left;
    }
    cout << endl;
}

// Driver code
int main() {
    // Creating the binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    Solution sol;
    Node* head = sol.bToDLL(root);

    // Print the doubly linked list
    printList(head);
    printReverse(head);

    return 0;
}
