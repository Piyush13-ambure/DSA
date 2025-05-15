/*You are given a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, we can select two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.

Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.*/

#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int moves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // moves needed is abs(left) + abs(right)
        moves += abs(left) + abs(right);

        // return net excess candies to parent
        return root->data + left + right - 1;
    }

    int distributeCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};

// Helper function to create a tree from example input like [3, 0, 0]
Node* buildExampleTree1() {
    Node* root = new Node(3);
    root->left = new Node(0);
    root->right = new Node(0);
    return root;
}

Node* buildExampleTree2() {
    Node* root = new Node(3);
    root->left = new Node(0);
    root->right = new Node(0);

    // Flip to match [0,3,0] (3 in the left child)
    root->data = 0;
    root->left->data = 3;
    return root;
}

int main() {
    Solution sol;

    Node* root1 = buildExampleTree1();
    cout << "Moves for tree [3,0,0]: " << sol.distributeCandy(root1) << endl;

    Node* root2 = buildExampleTree2();
    cout << "Moves for tree [0,3,0]: " << sol.distributeCandy(root2) << endl;

    return 0;
}
