//Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
//Answers are guaranteed to be fit into a 32 bit integer.


#include <iostream>
using namespace std;

class Solution {
public:
    int countWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        int prev2 = k, prev1 = k * k, curr;

        for (int i = 3; i <= n; i++) {
            curr = (prev1 + prev2) * (k - 1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

// Driver Code
int main() {
    Solution sol;
    int n = 3, k = 2; // Example: 3 posts, 2 colors
    cout << "Number of ways to paint the fence: " << sol.countWays(n, k) << endl;
    return 0;
}
