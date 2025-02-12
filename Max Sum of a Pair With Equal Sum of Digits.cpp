/*You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = digitSum(num);

            // If the same sum of digits exists, calculate the sum
            if (digitSumMap.find(sumDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sumDigits] + num);
            }

            // Update the map with the max number having this digit sum
            digitSumMap[sumDigits] = max(digitSumMap[sumDigits], num);
        }

        return maxSum;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {18, 43, 36, 13, 7};
    cout << "Output: " << sol.maximumSum(nums1) << endl;  // Expected: 54

    vector<int> nums2 = {10, 12, 19, 14};
    cout << "Output: " << sol.maximumSum(nums2) << endl;  // Expected: -1

    return 0;
}
