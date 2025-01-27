//Given an array arr[] of integers and another integer target. Find all unique quadruples from the given array that sums up to target.

//Note: All the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] it should be : q1 <= q2 <= q3 <= q4.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Function to find all unique quadruples that sum up to the target
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> result;
        int n = arr.size();
        
        // Sort the array to simplify finding quadruples
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 3; i++) {
            // Avoid duplicates for the first number
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Avoid duplicates for the second number
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];

                    if (sum == target) {
                        result.push_back({arr[i], arr[j], arr[left], arr[right]});

                        // Move the left and right pointers to avoid duplicates
                        while (left < right && arr[left] == arr[left + 1]) left++;
                        while (left < right && arr[right] == arr[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;
    vector<vector<int>> result = sol.fourSum(arr, target);

    // Print the result
    cout << "Quadruples that sum up to " << target << ":\n";
    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
