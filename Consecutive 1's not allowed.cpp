//Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.




#include <iostream>
using namespace std;

class Solution {
public:
    int countStrings(int n) {
        if (n == 1) return 2;
        if (n == 2) return 3;

        int prev2 = 2, prev1 = 3, curr;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    cout << "Number of valid binary strings: " << sol.countStrings(n) << endl;
    
    return 0;
}
