//Given two integers N and K, the task is to find the string S of minimum length such that it contains all possible strings of size N as a substring. The characters of the string should be from integers ranging from 0 to K-1.  


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS and construct Eulerian cycle
    void dfs(string node, unordered_map<string, vector<char>>& adj, string& result) {
        while (!adj[node].empty()) {
            char nextChar = adj[node].back();
            adj[node].pop_back();
            dfs(node.substr(1) + nextChar, adj, result);
        }
        result += node[0];  // Append current node's character
    }

    string findString(int n, int k) {
        unordered_map<string, vector<char>> adj;  // adjacency list
        string startNode;

        // Create all nodes of length (n-1) and their outgoing edges
        for (int i = 0; i < pow(k, n-1); i++) {
            string node = "";
            int temp = i;
            for (int j = 0; j < n-1; j++) {
                node = char('0' + (temp % k)) + node;
                temp /= k;
            }
            for (int j = 0; j < k; j++) {
                adj[node].push_back('0' + j);
            }
            if (i == 0) startNode = node;
        }

        string result;
        dfs(startNode, adj, result);
        
        // We reverse the result since our DFS adds in reverse order
        reverse(result.begin(), result.end());
        result += startNode.substr(1);  // Add the initial part to complete the cycle
        
        return result;
    }
};

// Testing the implementation
int main() {
    Solution sol;
    cout << sol.findString(2, 2) << endl;  // Output: "00110" or any rotation
    cout << sol.findString(3, 2) << endl;  // Output: "0001011100" or any rotation
    cout << sol.findString(1, 2) << endl;  // Output: "01" or "10"
    cout << sol.findString(2, 3) << endl;  // Output: "001122012" or any rotation
    return 0;
}
