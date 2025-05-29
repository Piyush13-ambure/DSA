/*Given a binary tree and data value of two of its nodes. Find the number of turns needed to reach from one node to another in the given binary tree.

Your Task:  
You don't need to read input or print anything. Complete the function NumberOFTurns() which takes root node and data value of 2 nodes as input parameters and returns the number of turns required to navigate between them. If the two nodes are in a straight line, ie- the path does not involve any turns, return -1.

*/

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Find LCA of the two nodes
    Node* findLCA(Node* root, int a, int b) {
        if (!root) return nullptr;
        if (root->data == a || root->data == b) return root;

        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);

        if (leftLCA && rightLCA) return root;
        return leftLCA ? leftLCA : rightLCA;
    }

    // Count turns from root to target node
    bool countTurns(Node* root, int target, int& turns, char prevDir) {
        if (!root) return false;
        if (root->data == target) return true;

        // Try left with updated direction
        if (countTurns(root->left, target, turns, 'L')) {
            if (prevDir == 'R') turns++;
            return true;
        }

        // Try right with updated direction
        if (countTurns(root->right, target, turns, 'R')) {
            if (prevDir == 'L') turns++;
            return true;
        }

        return false;
    }

    int NumberOFTurns(Node* root, int first, int second) {
        Node* lca = findLCA(root, first, second);
        if (!lca) return -1;

        int turns = 0;

        if (lca->data != first && lca->data != second) {
            // Both nodes are below LCA
            int turnsLeft = 0, turnsRight = 0;
            countTurns(lca->left, first, turnsLeft, 'L');
            countTurns(lca->right, second, turnsRight, 'R');
            turns = turnsLeft + turnsRight + 1; // +1 for the turn at LCA
        } else if (lca->data == first) {
            countTurns(lca, second, turns, 'N');
        } else if (lca->data == second) {
            countTurns(lca, first, turns, 'N');
        }

        return turns == 0 ? -1 : turns;
    }
};
