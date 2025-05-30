/*Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given LinkedList and return the root of the tree.
The result will be judged by printing the level order traversal of the Binary tree.

Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.*/



#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}



class Solution {
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
        if (!head) return NULL;

        TreeNode* root = new TreeNode(head->data);
        queue<TreeNode*> q;
        q.push(root);
        head = head->next;

        while (head) {
            TreeNode* parent = q.front();
            q.pop();

            // Left child
            parent->left = new TreeNode(head->data);
            q.push(parent->left);
            head = head->next;
            
            // Right child (if available)
            if (head) {
                parent->right = new TreeNode(head->data);
                q.push(parent->right);
                head = head->next;
            }
        }
        return root;
    }
};






int main() {
    int T;

    cin >> T;
    cin.ignore();
    while (T--) {
        struct Node *head = NULL;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            a.push_back(num); // Read the array elements from input string
            push(&head, num); // Add to linked list
        }

        reverses(&head);
        Node *prevhead = head;
        Solution obj;

        TreeNode *root = obj.linkedListToBinaryTree(head);
        if (root == NULL) {
            cout << "[]\n";
        } else {
            lvl(root);
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
