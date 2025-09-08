/*You are given an array arr[], containing non-negative integers. Additionally, you have q queries represented as a 2D array queries[][], where each query is of the form [xi , mi].
For each query, your task is to find the maximum bitwise XOR value between xi and any element in arr[] that is less than or equal to mi. In other words, for each query [xi , mi], compute: max( arr[j] XOR xi ) for all j such that arr[j]  ≤  mi .

If there is no element in arr[] that satisfies the condition arr[j]  ≤  mi , then the answer for that query should be -1.
Return an array ans[], where ans[i] represents the result of the i-th query*/



class node {
  public:
    node *left;  // 0
    node *right; // 1
};

class trie {
    node *root;

  public:
    trie() { root = new node(); }

    void insert(int n) {
        node *temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (temp->left == NULL) {
                    temp->left = new node();
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int max_XOR_helper(int value) {
        int current_ans = 0;
        node *temp = root;
        for (int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if (bit == 0) {
                // find opp value
                if (temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1 << j);
                } else {
                    temp = temp->left;
                }
            } else {
                // look for a zero
                if (temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1 << j);
                } else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }
};

class Solution {
  public:
    vector<int> maxXor(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size(), q = queries.size();
        vector<int> ans(q);
        vector<vector<int>> qry;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < q; i++) {
            qry.push_back({queries[i][1], queries[i][0], i});
        }
        sort(qry.begin(), qry.end());
        int j = 0;
        trie tree;
        for (int i = 0; i < q; i++) {
            while (j < arr.size() and arr[j] <= qry[i][0]) {
                tree.insert(arr[j++]);
            }
            if (j == 0)
                ans[qry[i][2]] = -1;
            else
                ans[qry[i][2]] = tree.max_XOR_helper(qry[i][1]);
        }
        return ans;
    }
};
