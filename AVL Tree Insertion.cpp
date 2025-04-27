/*Given an AVL tree and N values to be inserted in the tree. Write a function to insert elements into the given AVL tree.

Note:
The tree will be checked after each insertion. 
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all insertions are successful, inorder traversal of the tree will be printed.

*/


#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class Solution {
public:
    int height(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insertToAVL(Node* node, int data) {
        if (!node)
            return new Node(data);

        // BST Insertion
        if (data < node->data)
            node->left = insertToAVL(node->left, data);
        else if (data > node->data)
            node->right = insertToAVL(node->right, data);
        else // Equal keys not allowed in BST
            return node;

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor
        int balance = getBalance(node);

        // Balancing cases

        // Left Left
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        // Right Right
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        // Left Right
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
};

// Driver Code
int main() {
    Solution obj;
    Node* root = nullptr;

    int N;
    cout << "Enter number of nodes: ";
    cin >> N;

    int val;
    cout << "Enter values to insert: ";
    for (int i = 0; i < N; i++) {
        cin >> val;
        root = obj.insertToAVL(root, val);
    }

    cout << "Inorder traversal of constructed AVL tree: ";
    obj.inorderTraversal(root);
    cout << endl;

    return 0;
}
