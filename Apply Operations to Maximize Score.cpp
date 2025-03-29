/*You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;

vector<int> primeScore(MAXN, 0);

// Function to precompute the number of distinct prime factors for each number
void computePrimeScores() {
    for (int i = 2; i < MAXN; i++) {
        if (primeScore[i] == 0) { // Prime number
            for (int j = i; j < MAXN; j += i) {
                primeScore[j]++;
            }
        }
    }
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Compute prime scores for all elements in nums
        computePrimeScores();
        
        // Step 2: Create an array of pairs (prime_score, index)
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; i++) {
            elements.push_back({primeScore[nums[i]], i});
        }
        
        // Step 3: Sort elements based on prime score (descending)
        sort(elements.rbegin(), elements.rend());
        
        // Step 4: Find left and right limits using monotonic stacks
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        
        // Finding previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Finding next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }
        
        // Step 5: Use a priority queue to get max contribution efficiently
        long long result = 1;
        for (auto &[score, i] : elements) {
            if (k == 0) break;
            
            long long leftWays = i - left[i];   // Ways to pick left subarrays
            long long rightWays = right[i] - i; // Ways to pick right subarrays
            long long totalWays = leftWays * rightWays;
            
            long long pick = min((long long)k, totalWays);
            result = (result * pow(nums[i], pick, MOD)) % MOD;
            k -= pick;
        }
        
        return result;
    }

private:
    // Function to calculate (base^exp) % mod efficiently
    long long pow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {8, 3, 9, 3, 8};
    int k1 = 2;
    cout << "Output: " << solution.maximumScore(nums1, k1) << endl; // Expected: 81
    
    vector<int> nums2 = {19, 12, 14, 6, 10, 18};
    int k2 = 3;
    cout << "Output: " << solution.maximumScore(nums2, k2) << endl; // Expected: 4788
    
    return 0;
}
