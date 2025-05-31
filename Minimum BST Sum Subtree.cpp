/*Given a binary tree and a target, find the number of node in the minimum sub-tree with the given sum equal to the target which is also a binary search tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and target as input parameters which is a binary Tree and returns the length of the minimum subtree having a sum equal to the target but which is a binary search tree.*/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    int min_len;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
        int size;
        Info(bool b, int s, int minV, int maxV, int sz) :
            isBST(b), sum(s), minVal(minV), maxVal(maxV), size(sz) {}
    };

    Info dfs(Node* root, int target) {
        if (!root) return Info(true, 0, INT_MAX, INT_MIN, 0);

        Info left = dfs(root->left, target);
        Info right = dfs(root->right, target);

        bool is_bst = left.isBST && right.isBST &&
                      root->data > left.maxVal && root->data < right.minVal;

        int curr_sum = left.sum + right.sum + root->data;
        int curr_size = left.size + right.size + 1;

        if (is_bst && curr_sum == target) {
            min_len = min(min_len, curr_size);
        }

        return Info(
            is_bst,
            curr_sum,
            min(root->data, left.minVal),
            max(root->data, right.maxVal),
            curr_size
        );
    }

public:
    int minSubtreeSumBST(int target, Node *root) {
        min_len = INT_MAX;
        dfs(root, target);
        return (min_len == INT_MAX) ? -1 : min_len;
    }
};

// Utility function to build the example trees
Node* example1() {
    Node* root = new Node(13);
    root->left = new Node(5);
    root->right = new Node(23);
    root->left->right = new Node(17);
    root->left->right->left = new Node(16);
    return root;
}

Node* example2() {
    Node* root = new Node(7);
    root->right = new Node(23);
    root->right->left = new Node(10);
    root->right->right = new Node(23);
    root->right->left->right = new Node(17);
    return root;
}

int main() {
    Solution sol;

    // Test Case 1
    Node* root1 = example1();
    int target1 = 38;
    cout << "Output (Example 1): " << sol.minSubtreeSumBST(target1, root1) << endl;

    // Test Case 2
    Node* root2 = example2();
    int target2 = 73;
    cout << "Output (Example 2): " << sol.minSubtreeSumBST(target2, root2) << endl;

    return 0;
}

