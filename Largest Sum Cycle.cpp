/*Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).
You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn't have an exit. 
The task is to find the largest sum of a cycle in the maze(Sum of a cycle is the sum of the cell indexes of all cells present in that cycle).

Note:The cells are named with an integer value from 0 to N-1. If there is no cycle in the graph then return -1.
Your task:
You dont need to read input or print anything. Your task is to complete the function largestSumCycle() which takes the integer N denoting the number of cells and the array Edge[] as input parameters and returns the sum of the largest sum cycle in the maze.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long largestSumCycle(int N, vector<int> Edge) {
        vector<bool> visited(N, false);
        vector<int> time(N, -1);  // To record the time (step) of each node's visit
        long long maxCycleSum = -1;

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                unordered_map<int, int> path; // Node -> time visited in current DFS
                int curr = i, t = 0;

                while (curr != -1 && !visited[curr]) {
                    visited[curr] = true;
                    path[curr] = t;
                    time[curr] = t;
                    curr = Edge[curr];
                    ++t;
                }

                // If we revisit a node in the current DFS path, we found a cycle
                if (curr != -1 && path.find(curr) != path.end()) {
                    long long sum = 0;
                    for (auto& [node, t_val] : path) {
                        if (t_val >= path[curr]) {
                            sum += node;
                        }
                    }
                    maxCycleSum = max(maxCycleSum, sum);
                }
            }
        }

        return maxCycleSum;
    }
};

// Main function to demonstrate
int main() {
    Solution sol;

    int N1 = 4;
    vector<int> Edge1 = {1, 2, 0, -1};
    cout << "Output: " << sol.largestSumCycle(N1, Edge1) << endl; // Expected: 3

    int N2 = 4;
    vector<int> Edge2 = {2, 0, -1, 2};
    cout << "Output: " << sol.largestSumCycle(N2, Edge2) << endl; // Expected: -1

    return 0;
}


