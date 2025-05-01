/*Given an integer array arr[ ] and an integer k, the task is to check if the array arr[ ] could be divided into k non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isKPartitionPossible(vector<int> &arr, int k) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // If total sum is not divisible by k, can't partition
        if (sum % k != 0) return false;
        int target = sum / k;

        vector<bool> used(n, false);
        sort(arr.rbegin(), arr.rend());  // Sorting helps optimize backtracking

        return canPartition(0, k, 0, target, arr, used);
    }

private:
    bool canPartition(int index, int k, int currSum, int target, vector<int>& arr, vector<bool>& used) {
        if (k == 1) return true;  // Only one group left, must be valid
        if (currSum == target)    // Current group formed, start next group
            return canPartition(0, k - 1, 0, target, arr, used);

        for (int i = index; i < arr.size(); ++i) {
            if (!used[i] && currSum + arr[i] <= target) {
                used[i] = true;
                if (canPartition(i + 1, k, currSum + arr[i], target, arr, used))
                    return true;
                used[i] = false;
            }
        }

        return false;
    }
};

// Sample main function
int main() {
    Solution solution;

    vector<int> arr1 = {2, 1, 4, 5, 6};
    int k1 = 3;
    cout << "Input: [2, 1, 4, 5, 6], k = 3\nOutput: "
         << (solution.isKPartitionPossible(arr1, k1) ? "true" : "false") << endl;

    vector<int> arr2 = {2, 1, 5, 5, 6};
    int k2 = 3;
    cout << "Input: [2, 1, 5, 5, 6], k = 3\nOutput: "
         << (solution.isKPartitionPossible(arr2, k2) ? "true" : "false") << endl;

    return 0;
}
