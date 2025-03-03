//Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the BST  from the given preorder traversal. 

//In Pre-Order traversal, the root node is visited before the left child and right child nodes.


#include <bits/stdc++.h>
using namespace std;

/* Definition of a Binary Tree Node */
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to construct BST recursively
    Node* constructBST(int pre[], int& index, int size, int upper_bound) {
        if (index >= size || pre[index] > upper_bound) 
            return NULL;

        // Create the root node for this subtree
        Node* root = new Node(pre[index]);
        index++; // Move to the next element in preorder array

        // Construct left subtree with elements < root->data
        root->left = constructBST(pre, index, size, root->data);

        // Construct right subtree with elements < upper_bound
        root->right = constructBST(pre, index, size, upper_bound);

        return root;
    }

    // Function to construct BST from its preorder traversal
    Node* Bst(int pre[], int size) {
        int index = 0;
        return constructBST(pre, index, size, INT_MAX);
    }
};

// Utility function for postorder traversal
void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

// Driver Code
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        printPostorder(ob.Bst(arr, n));
        cout << endl;
    }
    return 0;
}

