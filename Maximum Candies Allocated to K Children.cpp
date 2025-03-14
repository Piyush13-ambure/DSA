/*You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        if (mid == 0) return false;  // Prevent division by zero
        long long count = 0;
        for (int c : candies) {
            count += c / mid;
            if (count >= k) return true; // Early stopping condition
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                ans = mid;
                left = mid + 1; // Try for a larger value
            } else {
                right = mid - 1; // Reduce possible value
            }
        }
        return ans;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    cout << sol.maximumCandies(candies, k) << endl; // Output: 5

    vector<int> candies2 = {2, 5};
    long long k2 = 11;
    cout << sol.maximumCandies(candies2, k2) << endl; // Output: 0

    return 0;
}
