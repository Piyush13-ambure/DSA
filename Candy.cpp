/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Start by giving each child 1 candy

        // First pass: left to right
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Second pass: right to left
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }

        return totalCandies;
    }
};

// Main function for testing
int main() {
    Solution sol;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Input: [1, 0, 2]\n";
    cout << "Output: " << sol.candy(ratings1) << endl; // Expected: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << "\nInput: [1, 2, 2]\n";
    cout << "Output: " << sol.candy(ratings2) << endl; // Expected: 4

    return 0;
}
