/*You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node *root) {
        if (!root) return {};

        map<int, int> topNodes;  // Stores the first node at each horizontal distance
        queue<pair<Node*, int>> q; // Queue for BFS traversal (Node, HD)

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int hd = it.second;

            // If HD is encountered first time, store it
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->data;
            }

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        vector<int> result;
        for (auto it : topNodes) {
            result.push_back(it.second);
        }
        return result;
    }
};

// Helper function to create a sample tree
Node* createSampleTree() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->left = new Node(90);
    root->right->right = new Node(100);
    return root;
}

// Main function
int main() {
    Node* root = createSampleTree();
    Solution solution;
    vector<int> result = solution.topView(root);

    cout << "Top View: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
