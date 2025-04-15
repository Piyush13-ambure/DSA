/*Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at a distance k from the given target node. No parent pointers are available.
Note:

You have to return the list in sorted order.
The tree will not contain duplicate values.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void buildParentMap(Node* root, unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {
        if (!root) return nullptr;
        if (root->data == target) return root;
        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parentMap;
        buildParentMap(root, parentMap);

        Node* targetNode = findTarget(root, target);
        if (!targetNode) return {};

        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        int currLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currLevel == k) break;
            while (size--) {
                Node* node = q.front(); q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentMap.find(node) != parentMap.end() &&
                    visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currLevel++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->data);
            q.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};

// Helper function to build the tree from level-order input
Node* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Main function
int main() {
    Solution sol;

    // Example: root = [1, 2, 3, 4, 5], target = 2, k = 2
    vector<int> treeNodes = {1, 2, 3, 4, 5};
    int target = 2;
    int k = 2;

    Node* root = buildTree(treeNodes);
    vector<int> result = sol.KDistanceNodes(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
