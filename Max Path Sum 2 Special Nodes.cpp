//Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.

//Note: Here special node is a node that is connected to exactly one different node.


#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree from input string
Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int maxSum = INT_MIN;

    // Function to check if a node is special (has only one child or is a leaf)
    bool isSpecial(Node* node) {
        return (!node->left && node->right) || (node->left && !node->right) || (!node->left && !node->right);
    }

    // Helper function to find max path sum between special nodes
    int findMaxPathSum(Node* root, bool &hasSpecial) {
        if (!root) return 0;

        bool leftSpecial = false, rightSpecial = false;
        int leftSum = findMaxPathSum(root->left, leftSpecial);
        int rightSum = findMaxPathSum(root->right, rightSpecial);

        // If current node is special
        if (isSpecial(root)) {
            hasSpecial = true;
        }

        // If both left and right have a special node, we calculate the possible max sum
        if (leftSpecial && rightSpecial) {
            maxSum = max(maxSum, leftSum + rightSum + root->data);
        }

        // Return max sum path including this node
        return root->data + max(leftSum, rightSum);
    }

    int maxPathSum(Node* root) {
        if (!root) return 0;

        bool hasSpecial = false;
        int result = findMaxPathSum(root, hasSpecial);
        return maxSum;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}
