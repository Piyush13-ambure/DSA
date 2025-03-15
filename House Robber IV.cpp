/*There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.*/




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if we can rob at least k houses with max capability <= mid
    bool canRob(vector<int>& nums, int k, int mid) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++; // Rob this house
                i++; // Skip next house (as adjacent houses cannot be robbed)
            }
            if (count >= k) return true; // Found at least k houses
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canRob(nums, k, mid)) {
                ans = mid; // Update answer and try for a smaller capability
                high = mid - 1;
            } else {
                low = mid + 1; // Increase capability requirement
            }
        }
        return ans;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 5, 9};
    int k1 = 2;
    cout << "Output: " << solution.minCapability(nums1, k1) << endl; // Expected: 5

    vector<int> nums2 = {2, 7, 9, 3, 1};
    int k2 = 2;
    cout << "Output: " << solution.minCapability(nums2, k2) << endl; // Expected: 2

    return 0;
}
