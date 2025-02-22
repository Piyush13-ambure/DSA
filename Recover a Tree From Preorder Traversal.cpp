/*We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

*/


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();
        
        while (i < n) {
            int depth = 0;
            // Count the number of dashes to determine the depth
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            // Extract the node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            
            // Create the new node
            TreeNode* node = new TreeNode(value);
            
            // If depth is less than stack size, pop elements to reach the correct parent
            while (st.size() > depth) {
                st.pop();
            }
            
            // Attach the node as left or right child
            if (!st.empty()) {
                if (!st.top()->left) st.top()->left = node;
                else st.top()->right = node;
            }
            
            // Push the new node to stack
            st.push(node);
        }
        
        // The root node is the first element in the stack
        while (st.size() > 1) {
            st.pop();
        }
        
        return st.top();
    }
};

// Utility function to print tree in preorder
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Driver code
int main() {
    Solution sol;
    
    string traversal1 = "1-2--3--4-5--6--7";
    TreeNode* root1 = sol.recoverFromPreorder(traversal1);
    printPreorder(root1); // Output: 1 2 3 4 5 6 7
    
    string traversal2 = "1-2--3---4-5--6---7";
    TreeNode* root2 = sol.recoverFromPreorder(traversal2);
    printPreorder(root2); // Output: 1 2 3 4 5 6 7
    
    return 0;
}
