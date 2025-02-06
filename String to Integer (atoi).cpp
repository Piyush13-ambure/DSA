//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer. The algorithm for myAtoi(string s) is as follows:

//Whitespace: Ignore any leading whitespace (" ").
//signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
//Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
//Return the integer as the final result.


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
