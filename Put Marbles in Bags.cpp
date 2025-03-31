/*You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:

No bag is empty.
If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0; // No partitioning needed

        vector<int> pairSums;
        for (int i = 0; i < n - 1; ++i) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }

        sort(pairSums.begin(), pairSums.end());

        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; ++i) {
            minScore += pairSums[i];                         // Smallest (k-1) elements
            maxScore += pairSums[n - 2 - i];                 // Largest (k-1) elements
        }

        return maxScore - minScore;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> weights = {1, 3, 5, 1}; 
    int k = 2;
    cout << "Difference: " << sol.putMarbles(weights, k) << endl;
    return 0;
}
