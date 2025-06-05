/*Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong.
  Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

    // In-order traversal to find the two swapped nodes
    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

  public:
    Node* correctBST(Node* root) {
        first = middle = last = prev = nullptr;

        inorder(root);

        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }

        return root;
    }
};

// Helper function to print inorder traversal
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Helper to manually create the tree from Example 1
Node* createExample1() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(20);
    return root;
}

// Helper to manually create the tree from Example 2
Node* createExample2() {
    Node* root = new Node(11);
    root->left = new Node(3);
    root->right = new Node(17);
    root->left->right = new Node(4);
    root->right->left = new Node(10);
    return root;
}

int main() {
    Solution sol;

    // Example 1
    Node* root1 = createExample1();
    cout << "Before correction (Inorder): ";
    printInorder(root1);
    cout << "\n";

    root1 = sol.correctBST(root1);

    cout << "After correction (Inorder): ";
    printInorder(root1);
    cout << "\n";

    // Example 2
    Node* root2 = createExample2();
    cout << "\nBefore correction (Inorder): ";
    printInorder(root2);
    cout << "\n";

    root2 = sol.correctBST(root2);

    cout << "After correction (Inorder): ";
    printInorder(root2);
    cout << "\n";

    return 0;
}
