//Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.There may be duplicates in the original array.

//Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countDrops = 0;

        // Count the number of places where order breaks
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {  // Using modulo to check the circular condition
                countDrops++;
            }
        }

        // The array can be rotated if there is at most one "drop"
        return countDrops <= 1;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> test1 = {3, 4, 5, 1, 2};  // True
    vector<int> test2 = {2, 1, 3, 4};     // False
    vector<int> test3 = {1, 2, 3, 4};     // True (already sorted)
    vector<int> test4 = {1, 1, 1, 1};     // True (already sorted)
    vector<int> test5 = {2, 2, 3, 3, 1};  // True (rotated sorted)

    cout << sol.check(test1) << endl;
    cout << sol.check(test2) << endl;
    cout << sol.check(test3) << endl;
    cout << sol.check(test4) << endl;
    cout << sol.check(test5) << endl;

    return 0;
}
