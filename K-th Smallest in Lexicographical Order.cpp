/*Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

*/
#include <iostream>
using namespace std;

class Solution {
public:
    long long countPrefix(long long n, long long prefix) {
        long long current = prefix, next = prefix + 1;
        long long count = 0;

        while (current <= n) {
            count += min(n + 1LL, next) - current;
            current *= 10;
            next *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1; // we've already considered '1'

        while (k > 0) {
            long long steps = countPrefix(n, curr);
            if (steps <= k) {
                // Move to next sibling
                curr++;
                k -= steps;
            } else {
                // Go deeper (like curr * 10)
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};

// Main function for testing
int main() {
    Solution sol;

    cout << "Output for n=13, k=2: " << sol.findKthNumber(13, 2) << endl; // Expected: 10
    cout << "Output for n=1, k=1: " << sol.findKthNumber(1, 1) << endl;   // Expected: 1
    cout << "Output for n=100, k=10: " << sol.findKthNumber(100, 10) << endl;

    return 0;
}
