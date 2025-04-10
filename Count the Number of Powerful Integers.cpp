/*You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.

A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.

Return the total number of powerful integers in the range [start..finish].

A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.

*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long count = 0;
        string suffix = s;

        // Get the numeric value of s
        long long base = stoll(suffix);
        long long mult = 1;

        for (int i = 0; i <= 15; ++i) { // 15 digits max for long long
            long long candidate = base + mult * i;

            // Build a prefix string (possibly empty) from i
            string prefix = to_string(i);
            string full = prefix + suffix;

            // Convert to number
            long long val = stoll(full);

            if (val < start) continue;
            if (val > finish) break;

            // Check if all digits are <= limit
            bool valid = true;
            for (char c : full) {
                if (c - '0' > limit) {
                    valid = false;
                    break;
                }
            }

            if (valid) count++;
        }

        // Alternatively use BFS or prefix generation up to a bound
        // Better approach below:

        // We'll try prefixes of any length (including "") that can be appended to s
        // and still be within finish. We generate such prefixes with digits <= limit.

        count = 0;
        string target = s;
        int len = to_string(finish).length();

        function<void(string)> dfs = [&](string prefix) {
            string full = prefix + target;
            if (full.length() > len) return;

            long long val = stoll(full);
            if (val > finish) return;
            if (val >= start) count++;

            for (int d = 0; d <= limit; ++d) {
                dfs(prefix + char('0' + d));
            }
        };

        // We don't want leading 0s unless the prefix is empty
        for (int d = 1; d <= limit; ++d) {
            dfs(string(1, char('0' + d)));
        }

        // Also check if s alone is a valid number in range
        long long val = stoll(s);
        bool valid = val >= start && val <= finish;
        for (char c : s) {
            if (c - '0' > limit) valid = false;
        }
        if (valid) count++;

        return count;
    }
};

// Example usage
int main() {
    Solution sol;

    cout << sol.numberOfPowerfulInt(1, 6000, 4, "124") << endl;     // Output: 5
    cout << sol.numberOfPowerfulInt(15, 215, 6, "10") << endl;      // Output: 2
    cout << sol.numberOfPowerfulInt(1000, 2000, 4, "3000") << endl; // Output: 0

    return 0;
}
