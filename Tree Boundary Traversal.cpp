/*Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to get the left boundary (excluding leaf nodes)
    void getLeftBoundary(Node* root, vector<int>& boundary) {
        Node* cur = root->left;
        while (cur) {
            if (!(cur->left == NULL && cur->right == NULL))
                boundary.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    // Function to get the leaf nodes in left-to-right order
    void getLeafNodes(Node* root, vector<int>& boundary) {
        if (!root) return;
        if (root->left == NULL && root->right == NULL) {
            boundary.push_back(root->data);
            return;
        }
        getLeafNodes(root->left, boundary);
        getLeafNodes(root->right, boundary);
    }

    // Function to get the right boundary (excluding leaf nodes)
    void getRightBoundary(Node* root, vector<int>& boundary) {
        Node* cur = root->right;
        stack<int> tempStack;
        while (cur) {
            if (!(cur->left == NULL && cur->right == NULL))
                tempStack.push(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while (!tempStack.empty()) {
            boundary.push_back(tempStack.top());
            tempStack.pop();
        }
    }

    // Main function for boundary traversal
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        
        vector<int> boundary;
        boundary.push_back(root->data);

        // Get left boundary excluding root & leaf nodes
        getLeftBoundary(root, boundary);

        // Get all leaf nodes
        getLeafNodes(root, boundary);

        // Get right boundary excluding root & leaf nodes, and reverse it
        getRightBoundary(root, boundary);

        return boundary;
    }
};

// Helper function to create a sample tree for testing
Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    return root;
}

// Main function
int main() {
    Node* root = createSampleTree();
    Solution solution;
    vector<int> result = solution.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
