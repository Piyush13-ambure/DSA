/*You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        unordered_set<int> seen;
        int n = digits.size();

        // Try all combinations of i, j, k where i != j != k
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue; // leading 0 is not allowed
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) {
                        seen.insert(num);
                    }
                }
            }
        }

        // Copy to result vector and sort
        res.assign(seen.begin(), seen.end());
        sort(res.begin(), res.end());
        return res;
    }
};

// Sample usage
int main() {
    Solution sol;

    vector<int> digits1 = {2, 1, 3, 0};
    vector<int> result1 = sol.findEvenNumbers(digits1);
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<int> digits2 = {2, 2, 8, 8, 2};
    vector<int> result2 = sol.findEvenNumbers(digits2);
    for (int num : result2) cout << num << " ";
    cout << endl;

    vector<int> digits3 = {3, 7, 5};
    vector<int> result3 = sol.findEvenNumbers(digits3);
    for (int num : result3) cout << num << " ";
    cout << endl;

    return 0;
}
