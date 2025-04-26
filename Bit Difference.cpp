/*We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f (2, 7) = 2.

You are given an array A of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all ordered pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countBits(int N, long long int A[]) {
        const int MOD = 1e9 + 7;
        long long ans = 0;

        // We check for 0 to 31 bits because A[i] < 2^31
        for (int bit = 0; bit < 32; ++bit) {
            long long countOn = 0;
            for (int i = 0; i < N; ++i) {
                if (A[i] & (1LL << bit)) {
                    countOn++;
                }
            }
            long long countOff = N - countOn;
            ans = (ans + (countOn * countOff * 2) % MOD) % MOD;
        }
        return (int)ans;
    }
};

int main() {
    int N;
    cin >> N;
    long long int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.countBits(N, A) << endl;

    return 0;
}
