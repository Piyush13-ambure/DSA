//Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : arr) {
            totalSum += num;
        }

        // If (totalSum - d) is odd or less than zero, no valid partitions exist
        if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) {
            return 0;
        }

        // Target sum for one of the subsets
        int target = (totalSum - d) / 2;

        // Dynamic programming table to count subsets with sum equal to target
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // There's one way to form sum 0 (empty subset)

        // Fill the dp array
        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};

int main() {
    int n, d;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the difference value (d): ";
    cin >> d;

    Solution sol;
    int result = sol.countPartitions(arr, d);

    cout << "The number of partitions with the given difference is: " << result << "\n";

    return 0;
}
