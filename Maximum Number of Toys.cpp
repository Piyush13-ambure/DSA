/*You are given N toys in a shop .
The cost of each toy is represented by an array A[]. You are given Q queries, For ith query, You have a C amount of money which you can use to purchase the toys. Also there are K broken toys and you won't purchase them. The task is to calculate the maximum number of toys you can purchase using the C amount of money.

Note: 1 based indexing is used. Each query is treated independently. 
Query definition: The first element represents an integer C where C=Queries[i][0].
The second element represents an integer K, where K = Queries[i][1].
The next K integers represent the indices of broken toys which are Queries[i][j] ,j>1
Your Task: 
You don't need to read input or print anything. Your task is to complete the function maximumToys() which takes the integer N and array A[ ],  integer Q and 2D array Queries[][] as input parameters and returns the array of answers of each query.*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumToys(int N, vector<int> A, int Q, vector<vector<int>> Queries) {
        vector<int> result;

        // Store the original toy prices with their indices
        vector<pair<int, int>> toys;
        for (int i = 0; i < N; ++i) {
            toys.push_back({A[i], i + 1}); // store 1-based index
        }

        // Sort toys by cost (cheapest first)
        sort(toys.begin(), toys.end());

        for (int i = 0; i < Q; ++i) {
            int C = Queries[i][0];
            int K = Queries[i][1];

            // Store broken indices in a set for fast lookup
            set<int> broken;
            for (int j = 0; j < K; ++j) {
                broken.insert(Queries[i][2 + j]);
            }

            int count = 0;
            int cost = 0;

            // Try to buy the cheapest available (non-broken) toys
            for (auto& toy : toys) {
                if (broken.find(toy.second) == broken.end()) {
                    if (cost + toy.first <= C) {
                        cost += toy.first;
                        count++;
                    } else {
                        break;
                    }
                }
            }

            result.push_back(count);
        }

        return result;
    }
};

// Main function for testing
int main() {
    Solution sol;

    // Example 1
    int N1 = 5;
    vector<int> A1 = {8, 6, 9, 2, 5};
    int Q1 = 2;
    vector<vector<int>> Queries1 = {{12, 2, 3, 4}, {30, 0}};
    vector<int> ans1 = sol.maximumToys(N1, A1, Q1, Queries1);
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Example 2
    int N2 = 2;
    vector<int> A2 = {3, 3};
    int Q2 = 1;
    vector<vector<int>> Queries2 = {{1, 0}};
    vector<int> ans2 = sol.maximumToys(N2, A2, Q2, Queries2);
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}


