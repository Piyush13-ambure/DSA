/*There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.

 */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);
        
        // Construct adjacency list representation of tree
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        // Step 1: Find Bob's path to 0 and record Bob's arrival time at each node
        vector<int> bobTime(n, -1);  // Bob's time at each node
        function<bool(int, int, int)> findBobPath = [&](int node, int parent, int time) {
            if (node == bob) { 
                bobTime[node] = time;
                return true;
            }
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                if (findBobPath(neighbor, node, time + 1)) {
                    bobTime[node] = time;
                    return true;
                }
            }
            return false;
        };
        findBobPath(0, -1, 0);
        
        // Step 2: DFS to compute Alice's maximum profit
        int maxProfit = INT_MIN;
        function<void(int, int, int, int)> dfsAlice = [&](int node, int parent, int time, int profit) {
            // Adjust profit based on Alice's and Bob's arrival times
            if (bobTime[node] == -1 || time < bobTime[node]) {
                profit += amount[node]; // Only Alice reaches, full profit
            } else if (time == bobTime[node]) {
                profit += amount[node] / 2; // They reach simultaneously, split the amount
            }
            
            // Check if it's a leaf node
            if (tree[node].size() == 1 && node != 0) {
                maxProfit = max(maxProfit, profit);
                return;
            }
            
            // Recur for children
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                dfsAlice(neighbor, node, time + 1, profit);
            }
        };
        dfsAlice(0, -1, 0, 0);

        return maxProfit;
    }
};

// Main function for testing
int main() {
    Solution solution;

    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob1 = 3;
    vector<int> amount1 = {-2, 4, 2, -4, 6};

    cout << "Test Case 1 Output: " << solution.mostProfitablePath(edges1, bob1, amount1) << endl;
    // Expected Output: 6

    vector<vector<int>> edges2 = {{0, 1}};
    int bob2 = 1;
    vector<int> amount2 = {-7280, 2350};

    cout << "Test Case 2 Output: " << solution.mostProfitablePath(edges2, bob2, amount2) << endl;
    // Expected Output: -7280

    return 0;
}
