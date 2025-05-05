/*Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->ch > b->ch; // Tie-breaker by character order
        return a->freq > b->freq; // Min-heap by frequency
    }
};

class Solution {
public:
    // Preorder traversal to collect Huffman codes
    void preorder(Node* root, string str, vector<string>& codes, unordered_map<char, string>& charToCode) {
        if (!root) return;

        // If it's a leaf node
        if (!root->left && !root->right) {
            charToCode[root->ch] = str;
        }

        preorder(root->left, str + "0", codes, charToCode);
        preorder(root->right, str + "1", codes, charToCode);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < N; ++i) {
            pq.push(new Node(S[i], f[i]));
        }

        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* merged = new Node(min(left->ch, right->ch), left->freq + right->freq);
            merged->left = left;
            merged->right = right;

            pq.push(merged);
        }

        Node* root = pq.top();
        unordered_map<char, string> charToCode;
        vector<string> result;

        preorder(root, "", result, charToCode);

        // Output in preorder traversal
        preorderCollect(root, "", result);
        return result;
    }

    // Separate function to collect only the codes in preorder for output
    void preorderCollect(Node* root, string str, vector<string>& result) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(str);
        }
        preorderCollect(root->left, str + "0", result);
        preorderCollect(root->right, str + "1", result);
    }
};

// Main function to test
int main() {
    Solution sol;
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = S.size();

    vector<string> codes = sol.huffmanCodes(S, f, N);

    for (const string& code : codes) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
