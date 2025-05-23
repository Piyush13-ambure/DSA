/*Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with the same value.*/

#include <iostream>
using namespace std;

// Linked List Node
struct LNode {
    int data;
    LNode* next;
    LNode(int x) {
        data = x;
        next = NULL;
    }
};

// Tree Node
struct TNode {
    int data;
    TNode* left;
    TNode* right;
    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    LNode* current;

    // Count nodes in the linked list
    int countNodes(LNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Recursive function to convert list to BST
    TNode* sortedListToBSTRecur(int n) {
        if (n <= 0) return NULL;

        // Recursively construct the left subtree
        TNode* left = sortedListToBSTRecur(n / 2);

        // Allocate memory for root, set data from current node
        TNode* root = new TNode(current->data);
        root->left = left;

        // Move to the next list node
        current = current->next;

        // Recursively construct the right subtree
        root->right = sortedListToBSTRecur(n - n / 2 - 1);

        return root;
    }

    // Main function to convert list to BST
    TNode* sortedListToBST(LNode* head) {
        int n = countNodes(head);
        current = head;
        return sortedListToBSTRecur(n);
    }
};

// Utility function to print preorder traversal of BST
void preorder(TNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    // Example: create a linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    LNode* head = new LNode(1);
    head->next = new LNode(2);
    head->next->next = new LNode(3);
    head->next->next->next = new LNode(4);
    head->next->next->next->next = new LNode(5);
    head->next->next->next->next->next = new LNode(6);
    head->next->next->next->next->next->next = new LNode(7);

    Solution obj;
    TNode* root = obj.sortedListToBST(head);

    // Output Preorder Traversal
    cout << "Preorder Traversal of constructed BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
