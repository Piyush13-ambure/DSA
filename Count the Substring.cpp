//Given a binary string S consists only of 0s and 1s. The task is to calculate the number of substrings that have more 1s than 0s.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstring(string S) {
        unordered_map<int, int> freq;  // To store prefix sum frequencies
        freq[0] = 1;  // Initialize with 0 sum for counting valid prefixes
        long long count = 0;
        int prefixSum = 0;

        for (char c : S) {
            // Convert '1' to +1, '0' to -1
            prefixSum += (c == '1') ? 1 : -1;

            // Count all prefix sums that are strictly less than the current prefixSum
            for (auto& [key, val] : freq) {
                if (key < prefixSum) {
                    count += val;
                }
            }

            // Update frequency of current prefixSum
            freq[prefixSum]++;
        }
        
        return count;
    }
};

// Driver function
int main() {
    Solution sol;
    cout << sol.countSubstring("011") << endl;  // Output: 4
    cout << sol.countSubstring("0000") << endl; // Output: 0
    return 0;
}
