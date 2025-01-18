//Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the maximum circular subarray sum
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Find the maximum subarray sum using Kadane's algorithm
        int maxNormal = kadane(arr);
        if (maxNormal < 0) {
            // If all elements are negative, the maximum circular sum is the maximum element
            return maxNormal;
        }

        // Step 2: Find the total sum of the array
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        // Step 3: Invert the array elements and apply Kadane's algorithm to find the minimum subarray sum
        for (int &num : arr) {
            num = -num;
        }
        int minSubarraySum = kadane(arr);

        // Step 4: Calculate the maximum circular subarray sum
        int maxCircular = totalSum + minSubarraySum; // Total sum - absolute value of the minimum subarray sum

        // Return the maximum of normal and circular subarray sums
        return max(maxNormal, maxCircular);
    }

private:
    // Helper function to find the maximum subarray sum using Kadane's algorithm
    int kadane(vector<int> &arr) {
        int maxEndingHere = 0, maxSoFar = INT_MIN;
        for (int num : arr) {
            maxEndingHere = max(num, maxEndingHere + num);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};

// Main function to test the Solution class
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.circularSubarraySum(arr);
    cout << "The maximum circular subarray sum is: " << result << endl;

    return 0;
}
