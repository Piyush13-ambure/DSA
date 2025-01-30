//Given two arrays of integers a[] and b[], the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        int sumA = 0, sumB = 0;
        for (int num : a) sumA += num;
        for (int num : b) sumB += num;

        // If (sumB - sumA) is odd, swapping is not possible
        if ((sumB - sumA) % 2 != 0) return false;

        int diff = (sumB - sumA) / 2;
        unordered_set<int> setB(b.begin(), b.end());

        // Check if there exists an `x` in `a` such that `x + diff` exists in `b`
        for (int x : a) {
            if (setB.count(x + diff)) return true;
        }
        return false;
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<int> a = {4, 1, 2, 1, 1, 2};
    vector<int> b = {3, 6, 3, 3};
    
    bool result = sol.findSwapValues(a, b);
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}
