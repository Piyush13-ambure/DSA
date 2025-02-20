//Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end()); // Store existing binary strings

        for (int i = 0; i < (1 << n); i++) { // Iterate from 0 to 2^n - 1
            string binary = bitset<16>(i).to_string().substr(16 - n); // Convert number to n-bit binary
            if (numSet.find(binary) == numSet.end()) // If not in set, return it
                return binary;
        }
        return ""; // Should never reach here
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<string> nums1 = {"01", "10"};
    cout << sol.findDifferentBinaryString(nums1) << endl; // Output: "11" or "00"

    vector<string> nums2 = {"00", "01"};
    cout << sol.findDifferentBinaryString(nums2) << endl; // Output: "10" or "11"

    vector<string> nums3 = {"111", "011", "001"};
    cout << sol.findDifferentBinaryString(nums3) << endl; // Output: "000", "010", "100", "101", or "110"

    return 0;
}
