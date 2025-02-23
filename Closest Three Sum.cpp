/*Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());  // Step 1: Sort the array
        int n = arr.size();
        int closestSum = INT_MAX;
        int maxClosestSum = INT_MIN;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                // If the sum is exactly the target, return it immediately
                if (sum == target) return sum;

                // If the current sum is closer, update the closest sum
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                    maxClosestSum = sum;
                } else if (abs(target - sum) == abs(target - closestSum)) {
                    // If two sums have the same difference, take the maximum one
                    maxClosestSum = max(maxClosestSum, sum);
                }

                // Adjust pointers based on the sum value
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return maxClosestSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {-7, 9, 8, 3, 1, 1};
    int target1 = 2;
    cout << sol.threeSumClosest(arr1, target1) << endl; // Output: 2

    vector<int> arr2 = {5, 2, 7, 5};
    int target2 = 13;
    cout << sol.threeSumClosest(arr2, target2) << endl; // Output: 14

    return 0;
}
