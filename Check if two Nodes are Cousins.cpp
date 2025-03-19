/*Given a binary tree (having distinct node values)root and two node values. Check whether or not the two nodes with values a and b are cousins.
Note: Two nodes of a binary tree are cousins if they have the same depth with different parents.

*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to find depth and parent of a given target node
    void findDepthAndParent(Node* root, int target, int depth, Node* parent, int &foundDepth, Node* &foundParent) {
        if (!root) return;

        if (root->data == target) {
            foundDepth = depth;
            foundParent = parent;
            return;
        }
        
        findDepthAndParent(root->left, target, depth + 1, root, foundDepth, foundParent);
        findDepthAndParent(root->right, target, depth + 1, root, foundDepth, foundParent);
    }

    // Function to check if two nodes are cousins
    bool isCousins(Node* root, int x, int y) {
        if (!root) return false;
        
        Node *parentX = NULL, *parentY = NULL;
        int depthX = -1, depthY = -1;
        
        // Find depth and parent for both nodes
        findDepthAndParent(root, x, 0, NULL, depthX, parentX);
        findDepthAndParent(root, y, 0, NULL, depthY, parentY);
        
        // Check if they are cousins (same depth, different parents)
        return (depthX == depthY) && (parentX != parentY);
    }
};

// Function to build a simple binary tree for testing
Node* buildTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    return root;
}

// Main function to test the solution
int main() {
    Solution sol;
    Node* root = buildTree();
    
    int a = 7, b = 12;
    cout << "Are nodes " << a << " and " << b << " cousins? " << (sol.isCousins(root, a, b) ? "True" : "False") << endl;

    return 0;
}

