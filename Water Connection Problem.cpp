/*There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.  
1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
2. Every house with only one incoming and no outgoing pipe gets a tap.
The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes an integer n(the number of houses), p(the number of pipes),the array a[] , b[] and d[] (where d[i] denoting the diameter of the ith pipe from the house a[i] to house b[i]) as input parameter and returns the array of pairs of tanks and taps installed i.e ith element of the array contains three integers: house number of tank, house number of tap and the minimum diameter of pipe between them. Note that, returned array must be sorted based on the house number containing a tank (i.e. smaller house number should come before a large house number).
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
        // Create arrays for incoming and outgoing pipes
        vector<int> in(n + 1, 0), out(n + 1, 0), diameter(n + 1, 0), next(n + 1, 0);

        // Build graph-like information
        for (int i = 0; i < p; i++) {
            int u = a[i], v = b[i], dia = d[i];
            out[u] = v;            // Outgoing from u to v
            in[v] = u;             // Incoming to v from u
            diameter[u] = dia;     // Diameter of pipe from u to v
        }

        vector<vector<int>> result;

        // Find all tank-tap pairs
        for (int i = 1; i <= n; i++) {
            // A house with an outgoing pipe and no incoming pipe — it's a tank location
            if (in[i] == 0 && out[i] != 0) {
                int start = i;
                int curr = i;
                int min_dia = INT_MAX;

                // Traverse the pipe path until tap (no outgoing)
                while (out[curr] != 0) {
                    min_dia = min(min_dia, diameter[curr]);
                    curr = out[curr];
                }

                // curr now points to the tap house
                result.push_back({start, curr, min_dia});
            }
        }

        // Sort by tank house number
        sort(result.begin(), result.end());

        return result;
    }
};

// Main function to demonstrate usage
int main() {
    int n = 9, p = 6;
    vector<int> a = {7, 5, 4, 2, 9, 3};
    vector<int> b = {4, 9, 6, 8, 7, 1};
    vector<int> d = {98, 72, 10, 22, 17, 66};

    Solution sol;
    vector<vector<int>> res = sol.solve(n, p, a, b, d);

    // Output
    cout << res.size() << endl;
    for (auto &row : res) {
        cout << row[0] << " " << row[1] << " " << row[2] << endl;
    }

    return 0;
}
