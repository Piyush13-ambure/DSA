/*Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the level order traversal of the tree returned by deSerialize(serialize(input_tree)).*/

/* class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void serializeUtil(Node *root, vector<int> &a) {
        // base case if node is null.
        if (root == NULL) {
            a.push_back(-1);
            return;
        }
        // storing the data at node in list.
        a.push_back(root->data);

        // calling function recursively for left and right subtrees.
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }

    vector<int> serialize(Node *root) {
        vector<int> serialized;
        serializeUtil(root, serialized);

        // returning the list.
        return serialized;
    }

    // Function to construct the tree.
    Node *kewl(vector<int> &a, int *index) {
        // base case if there are no more elements in list.
        if (*index == a.size() or a[*index] == -1) {
            *index += 1;
            return NULL;
        }

        // creating new node for storing current element.
        Node *root = new Node(a[*index]);
        *index += 1;

        // calling function recursively for left and right subtrees.
        root->left = kewl(a, index);
        root->right = kewl(a, index);
        return root;
    }

    Node *deSerialize(vector<int> &arr) {
        int index = 0;
        // returning the tree.
        return kewl(arr, &index);
    }
};
