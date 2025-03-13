//Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
//Returned triplet should also be internally sorted i.e. i<j<k.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> result;
        int n = arr.size();
        
        // Sort the array to use two-pointer approach
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for i
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    result.push_back({i, left, right});

                    // Skip duplicate values for left and right
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    vector<int> arr = {0, -1, 2, -3, 1};

    vector<vector<int>> triplets = sol.findTriplets(arr);

    cout << "Output: [";
    for (size_t i = 0; i < triplets.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j];
            if (j < triplets[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < triplets.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
