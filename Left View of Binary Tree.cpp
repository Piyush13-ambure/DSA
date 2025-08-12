/*Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    int max_level;

    // Function to get the left view of the binary tree.
    void leftViewUtil(vector<int>& result, Node* root, int level) {
        // if root is null, we simply return.
        if (root == nullptr)
            return;

        // if this is the first root of its level then it is in the left view.
        if (max_level < level) {
            // storing data of current root in list.
            result.push_back(root->data);
            max_level = level;
        }

        // calling function recursively for left and right subtrees of current root.
        leftViewUtil(result, root->left, level + 1);
        leftViewUtil(result, root->right, level + 1);
    }

  public:
    vector<int> leftView(Node* root) {
        max_level = 0;
        vector<int> result;
        leftViewUtil(result, root, 1);
        // returning the list.
        return result;
    }
};
