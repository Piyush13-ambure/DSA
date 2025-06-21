/*Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Your Task:
You don't need to read input or print anything. Complete the function checktree() which takes the array preorder[ ], inorder[ ], postorder[ ] and integer N as input parameters and returns true if the three traversals are of the same tree or not. */



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* buildTree(int preorder[], int inorder[], int start, int end, int& preIndex, unordered_map<int, int>& inMap) {
        if (start > end) return nullptr;

        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        if (start == end) return root;

        int inIndex = inMap[rootVal];

        root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex, inMap);
        root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex, inMap);

        return root;
    }

    void getPostorder(Node* root, vector<int>& post) {
        if (!root) return;
        getPostorder(root->left, post);
        getPostorder(root->right, post);
        post.push_back(root->data);
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < N; ++i)
            inMap[inorder[i]] = i;

        int preIndex = 0;
        Node* root = buildTree(preorder, inorder, 0, N - 1, preIndex, inMap);

        vector<int> generatedPost;
        getPostorder(root, generatedPost);

        for (int i = 0; i < N; ++i) {
            if (generatedPost[i] != postorder[i])
                return false;
        }

        return true;
    }
};

// 🔹 Main function to test the code
int main() {
    Solution obj;

    // ✅ Example 1
    int preorder1[] = {1, 2, 4, 5, 3};
    int inorder1[]  = {4, 2, 5, 1, 3};
    int postorder1[]= {4, 5, 2, 3, 1};
    int N1 = 5;

    cout << "Example 1: ";
    cout << (obj.checktree(preorder1, inorder1, postorder1, N1) ? "Yes" : "No") << endl;

    // ❌ Example 2
    int preorder2[] = {1, 5, 4, 2, 3};
    int inorder2[]  = {4, 2, 5, 1, 3};
    int postorder2[]= {4, 1, 2, 3, 5};
    int N2 = 5;

    cout << "Example 2: ";
    cout << (obj.checktree(preorder2, inorder2, postorder2, N2) ? "Yes" : "No") << endl;

    return 0;
}
