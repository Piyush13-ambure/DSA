/*It is a universal fact that Geekina hates 1s however it is also known that Geekina loves the integers having atmost k 1s (set-bits) in their binary representation. 

Geekina demanded nth such non-negative number from Geek, and being a good friend of Geek, now it's your responsibility to tell him that number.

Note: The test cases are generated such that the answer always exists and will fit in the 64-bit data type.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function findNthNumer() that takes n and k as input parameters. Return the nth number having at most k set-bits.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to compute nCr
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    // Count how many numbers <= num have at most k set bits
    long long countNumbersWithAtMostKSetBits(long long num, int k) {
        long long count = 0;
        int bits = 0;
        for (int i = 63; i >= 0; i--) {
            if ((num >> i) & 1) {
                count += nCr(i, k - bits);
                bits++;
                if (bits > k) break;
            }
        }
        if (bits <= k) count++;  // Include num itself if it has at most k set bits
        return count;
    }

    long long findNthNumber(int n, int k) {
        long long low = 0, high = (1LL << 63) - 1;
        long long ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countNumbersWithAtMostKSetBits(mid, k) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "The " << n << "-th number with at most " << k << " set bits is: ";
    cout << sol.findNthNumber(n, k) << endl;
    return 0;
}
