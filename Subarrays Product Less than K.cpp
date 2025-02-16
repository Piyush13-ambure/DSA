//Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        if (k <= 1) return 0; // No subarrays possible if k is <= 1

        long long product = 1, count = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            product *= arr[right];

            // Shrink the window if product >= k
            while (product >= k && left <= right) {
                product /= arr[left++];
            }

            // Count subarrays ending at 'right'
            count += (right - left + 1);
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = {1, 2, 3, 4};
    int n1 = arr1.size();
    long long k1 = 10;
    cout << "Output: " << solution.countSubArrayProductLessThanK(arr1, n1, k1) << endl; // Expected: 7

    vector<int> arr2 = {1, 9, 2, 8, 6, 4, 3};
    int n2 = arr2.size();
    long long k2 = 100;
    cout << "Output: " << solution.countSubArrayProductLessThanK(arr2, n2, k2) << endl; // Expected: 16

    return 0;
}
