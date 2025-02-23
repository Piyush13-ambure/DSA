/*Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.*/


class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        
        int preIndex = 0;
        return buildTree(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
    }
    
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, 
                        int& preIndex, int postStart, int postEnd) {
        if (preIndex >= preorder.size() || postStart > postEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        if (postStart == postEnd || preIndex >= preorder.size()) return root;
        
        int leftSubtreeIndex = postIndex[preorder[preIndex]];
        
        if (leftSubtreeIndex < postEnd) {
            root->left = buildTree(preorder, postorder, postIndex, preIndex, postStart, leftSubtreeIndex);
            root->right = buildTree(preorder, postorder, postIndex, preIndex, leftSubtreeIndex + 1, postEnd - 1);
        }
        
        return root;
    }
};
