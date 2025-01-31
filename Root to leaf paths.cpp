//Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

//Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.


#include <iostream>
#include <vector>
using namespace std;

// Definition for Binary Tree Node
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
    void findPaths(Node* root, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        // Add current node to path
        path.push_back(root->data);

        // If leaf node, store the path
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            // Recur left first, then right
            findPaths(root->left, path, result);
            findPaths(root->right, path, result);
        }

        // Backtrack: remove last node before returning
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        findPaths(root, path, result);
        return result;
    }
};

// Helper function to print paths
void printPaths(const vector<vector<int>>& paths) {
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    printPaths(paths);
    return 0;
}
