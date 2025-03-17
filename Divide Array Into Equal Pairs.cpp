/*You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all numbers appear in even count
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};

// Driver code
int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 3, 2, 2, 2};
    cout << "Output: " << sol.divideArray(nums1) << endl;  // Expected Output: true

    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Output: " << sol.divideArray(nums2) << endl;  // Expected Output: false

    return 0;
}
