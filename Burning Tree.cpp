/*Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

// Tree Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class
class Solution {
public:
    void mapParents(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) {
                targetNode = curr;
            }
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = nullptr;
        mapParents(root, parent, targetNode, target);

        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();

                if (curr->left && visited.find(curr->left) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    flag = true;
                }
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    flag = true;
                }
                if (parent.find(curr) != parent.end() && visited.find(parent[curr]) == visited.end()) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                    flag = true;
                }
            }

            if (flag) time++;
        }

        return time;
    }
};

// Utility function to build tree from level order
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return NULL;

    vector<string> ip;
    stringstream ss(str);
    string temp;
    while (ss >> temp) ip.push_back(temp);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();

        if (ip[i] != "N") {
            curr->left = new Node(stoi(ip[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            curr->right = new Node(stoi(ip[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Main function
int main() {
    string tree_input = "1 2 3 4 5 N 6 N N 7 8 N 9 N N N N N 10";
    int target = 8;

    Node* root = buildTree(tree_input);

    Solution sol;
    int result = sol.minTime(root, target);

    cout << "Minimum time to burn the tree: " << result << endl;

    return 0;
}
