/*You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:

subs has a size of at least k.
Character a has an odd frequency in subs.
Character b has an even frequency in subs.
Return the maximum difference.

Note that subs can contain more than 2 distinct characters.*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.length();
        int maxDiff = INT_MIN;

        // Iterate over all possible starting points for the substring
        for (int start = 0; start <= n - k; start++) {
            unordered_map<char, int> freq;
            // Count frequencies for the substring of length at least k
            for (int end = start; end < n; end++) {
                freq[s[end]]++;

                // Only consider substrings of length at least k
                if (end - start + 1 >= k) {
                    int oddFreq = INT_MIN;
                    int evenFreq = INT_MIN;

                    // Find the maximum odd and even frequencies
                    for (const auto& entry : freq) {
                        char ch = entry.first;
                        int count = entry.second;

                        if (count % 2 == 0) {
                            evenFreq = max(evenFreq, count);
                        } else {
                            oddFreq = max(oddFreq, count);
                        }
                    }

                    // Calculate the difference if both odd and even frequencies exist
                    if (oddFreq != INT_MIN && evenFreq != INT_MIN) {
                        maxDiff = max(maxDiff, oddFreq - evenFreq);
                    }
                }
            }
        }

        return (maxDiff == INT_MIN) ? -1 : maxDiff;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test case 1
    string s1 = "12233";
    int k1 = 4;
    cout << "Output: " << sol.maxDifference(s1, k1) << endl; // Expected output: -1

    // Test case 2
    string s2 = "1122211";
    int k2 = 3;
    cout << "Output: " << sol.maxDifference(s2, k2) << endl; // Expected output: 1

    // Test case 3
    string s3 = "110";
    int k3 = 3;
    cout << "Output: " << sol.maxDifference(s3, k3) << endl; // Expected output: -1

    return 0;
}
