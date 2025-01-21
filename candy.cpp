//There are n children standing in a line. Each child is assigned a rating value given in the integer array arr[]. You are giving candies to these children subjected to the following requirements:

//Each child must have at least one candy.
//Children with a higher rating than their neighbors get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1); // Step 1: Each child gets at least one candy

        // Step 2: Traverse from left to right
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up candies
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

// Main function
int main() {
    Solution solution;

    vector<int> arr = {1, 0, 2}; // Example input
    cout << "Minimum candies needed: " << solution.minCandy(arr) << endl;

    vector<int> arr2 = {1, 2, 2}; // Another example input
    cout << "Minimum candies needed: " << solution.minCandy(arr2) << endl;

    return 0;
}
