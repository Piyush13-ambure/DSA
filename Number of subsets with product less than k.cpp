//Given an array arr. Find the number of non-empty subsets whose product of elements is less than or equal to a given integer k.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubsets(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Function to generate all subsets and store valid product values
        auto generateSubsets = [&](vector<int>& nums) {
            vector<int> products;
            int m = nums.size();
            for (int mask = 0; mask < (1 << m); mask++) {
                int product = 1;
                bool valid = true;
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        if (product > k / nums[i]) { // Avoid overflow
                            valid = false;
                            break;
                        }
                        product *= nums[i];
                    }
                }
                if (valid) products.push_back(product);
            }
            return products;
        };

        // Split array into two halves
        vector<int> left(arr.begin(), arr.begin() + n / 2);
        vector<int> right(arr.begin() + n / 2, arr.end());

        // Generate all subset products for left and right halves
        vector<int> leftProducts = generateSubsets(left);
        vector<int> rightProducts = generateSubsets(right);

        // Sort rightProducts to allow binary search
        sort(rightProducts.begin(), rightProducts.end());

        // Count valid pairs
        int count = 0;
        for (int product : leftProducts) {
            count += upper_bound(rightProducts.begin(), rightProducts.end(), k / product) - rightProducts.begin();
        }

        // Subtract 1 to remove the empty subset
        return count - 1;
    }
};

// Main function to test the solution
int main() {
    Solution obj;
    
    // Example 1
    vector<int> arr1 = {2, 4, 5, 3};
    int k1 = 12;
    cout << obj.numOfSubsets(arr1, k1) << endl;  // Output: 8
    
    // Example 2
    vector<int> arr2 = {9, 8, 3};
    int k2 = 2;
    cout << obj.numOfSubsets(arr2, k2) << endl;  // Output: 0

    // Example 3
    vector<int> arr3 = {9, 2, 2};
    int k3 = 2;
    cout << obj.numOfSubsets(arr3, k3) << endl;  // Output: 2

    return 0;
}
