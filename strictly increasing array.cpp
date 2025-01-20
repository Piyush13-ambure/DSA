//Given an array nums of n positive integers. Find the minimum number of operations required to modify the array such that array elements are in strictly increasing order (nums[i] < nums[i+1]).
//Changing a number to greater or lesser than an original number is counted as one operation.

//Note: Array elements can become negative after applying the operation.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min_operations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                // Calculate the operations needed to make nums[i] > nums[i-1]
                int needed = nums[i - 1] - nums[i] + 1;
                nums[i] += needed;
                operations += needed;
            }
        }

        return operations;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 1};
    cout << "Minimum operations: " << solution.min_operations(nums) << endl;

    nums = {3, 2, 1, 2, 1, 7};
    cout << "Minimum operations: " << solution.min_operations(nums) << endl;

    return 0;
}
