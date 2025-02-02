//Given a string s, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return -1 if no such string exists.

//Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

//For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because its first occurrence appears before the first occurrence of "hi".



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestSubstring(string& s) {
        int n = s.size();
        int left = 1, right = n, bestLen = 0;
        string bestSubstr = "-1";
        
        auto search = [&](int len) -> string {
            unordered_map<size_t, int> seen; // Hash -> First occurrence index
            size_t base = 31, mod = 1e9 + 7;
            size_t hash = 0, power = 1;
            
            // Compute hash for the first `len` characters
            for (int i = 0; i < len; i++) {
                hash = (hash * base + s[i]) % mod;
                if (i > 0) power = (power * base) % mod;
            }
            seen[hash] = 0;

            // Sliding window to compute rolling hashes
            for (int i = 1; i <= n - len; i++) {
                hash = ((hash - s[i - 1] * power % mod + mod) * base + s[i + len - 1]) % mod;

                if (seen.count(hash)) {
                    int prevIdx = seen[hash];
                    if (prevIdx + len <= i) return s.substr(prevIdx, len);
                } else {
                    seen[hash] = i;
                }
            }
            return "";
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            string candidate = search(mid);
            if (!candidate.empty()) {
                bestLen = mid;
                bestSubstr = candidate;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bestSubstr;
    }
};

int main() {
    Solution sol;
    string s = "abhihiab";
    cout << sol.longestSubstring(s) << endl; // Output: "ab"
    return 0;
}
