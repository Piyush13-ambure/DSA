/*Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) // If remainder is 2, it's not possible
                return false;
            n /= 3; // Reduce n by dividing by 3
        }
        return true;
    }
};

// Driver code
int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << (sol.checkPowersOfThree(n) ? "true" : "false") << endl;
    return 0;
}
