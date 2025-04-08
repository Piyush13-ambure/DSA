/*Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

*/

#include <iostream>
using namespace std;

// A binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Find the LCA of two nodes
    Node* findLCA(Node* root, int a, int b) {
        if (root == nullptr) return nullptr;
        if (root->data == a || root->data == b) return root;

        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);

        if (leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }

    // Find the distance from root to a given target node
    int findLevel(Node* root, int target, int level) {
        if (root == nullptr) return -1;
        if (root->data == target) return level;

        int left = findLevel(root->left, target, level + 1);
        if (left != -1) return left;

        return findLevel(root->right, target, level + 1);
    }

    // Main function to return distance between nodes a and b
    int findDist(Node* root, int a, int b) {
        Node* lca = findLCA(root, a, b);
        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);
        return d1 + d2;
    }
};

// Build a sample tree for testing
Node* buildExampleTree1() {
    // Tree: [1, 2, 3]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return root;
}

Node* buildExampleTree2() {
    // Tree: [11, 22, 33, 44, 55, 66, 77]
    Node* root = new Node(11);
    root->left = new Node(22);
    root->right = new Node(33);
    root->left->left = new Node(44);
    root->left->right = new Node(55);
    root->right->left = new Node(66);
    root->right->right = new Node(77);
    return root;
}

int main() {
    Solution sol;

    Node* root1 = buildExampleTree1();
    cout << "Distance between 2 and 3: " << sol.findDist(root1, 2, 3) << endl; // Output: 2
    cout << "Distance between 1 and 3: " << sol.findDist(root1, 1, 3) << endl; // Output: 1

    Node* root2 = buildExampleTree2();
    cout << "Distance between 77 and 22: " << sol.findDist(root2, 77, 22) << endl; // Output: 3

    return 0;
}
