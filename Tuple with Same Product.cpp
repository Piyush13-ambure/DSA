//Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size(), result = 0;

        // Store frequency of all possible products
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Count valid tuples
        for (auto& it : productCount) {
            int count = it.second;
            if (count > 1) {
                result += (count * (count - 1) / 2) * 8;
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 4, 6};
    cout << sol.tupleSameProduct(nums1) << endl;  // Output: 8

    vector<int> nums2 = {1, 2, 4, 5, 10};
    cout << sol.tupleSameProduct(nums2) << endl;  // Output: 16

    return 0;
}
