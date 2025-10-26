/*Given the root of a binary tree, your task is to find the diameter of the binary tree.

The diameter (also called the width) of a binary tree is defined as the number of edges on the longest path between any two leaf nodes. Note that this path may or may not pass through the root of the tree.*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the diameter of a Binary Tree.
    int diameterRecur(Node* root, int& res) {
        // Base case: tree is empty
        if (root == nullptr)
            return 0;

        // find the height of left and right subtree
        // (it will also find of diameter for left
        // and right subtree).
        int lHeight = diameterRecur(root->left, res);
        int rHeight = diameterRecur(root->right, res);

        // Check if diameter of root is greater
        // than res.
        res = max(res, lHeight + rHeight);

        // return the height of current subtree.
        return 1 + max(lHeight, rHeight);
    }

    int diameter(Node* root) {
        int res = 0;
        diameterRecur(root, res);
        return res;
    }
};
