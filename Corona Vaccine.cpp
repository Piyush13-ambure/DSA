/*Geek has successfully developed an effective vaccine for the Coronavirus and aims to ensure that every house in Geek Land has access to it. The houses in Geek Land are structured as a binary tree, where each node represents a house, and the edges denote direct connections between houses.

Each house that receives a vaccine kit can provide coverage to:

Itself
Its direct parent house (if it exists)
Its immediate child houses (if any exist)
Your task is to determine the minimum number of houses that must be supplied with a vaccine kit to ensure that every house is covered.*/


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    int ans;

    // Postorder traversal to check the vaccination status of each node.
    int post(Node* node) {
        bool zero = false, two = false;
        if (node->left == NULL && node->right == NULL)
            return 0;

        // Checking left subtree
        if (node->left) {
            int get = post(node->left);
            if (get == 0)
                zero = true;
            if (get == 2)
                two = true;
        }

        // Checking right subtree
        if (node->right) {
            int get = post(node->right);
            if (get == 0)
                zero = true;
            if (get == 2)
                two = true;
        }

        // Updating the vaccination status of the current node
        if (zero == true) {
            ans++;
            return 2;
        }

        if (two == true) {
            return 1;
        }
        return 0;
    }

  public:
    // Function to calculate the minimum number of vaccines needed.
    int supplyVaccine(Node* root) {
        ans = 0;
        // Calling postorder traversal to check vaccination status of each node.
        int result = post(root);

        // Checking the vaccination status of the root node to determine the final
        // result.
        if (result == 0)
            return (ans + 1);
        return ans;
    }
};
