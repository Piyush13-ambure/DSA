/*Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.*/


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    // Function to return the second largest element
    int getSecondLargest(vector<int> &arr) {
        int first = INT_MIN, second = INT_MIN;
        
        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num < first) {
                second = num;
            }
        }
        
        return (second == INT_MIN) ? -1 : second;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {12, 35, 1, 10, 34, 1};
    vector<int> arr2 = {10, 5, 10};
    vector<int> arr3 = {10, 10, 10};

    cout << "Output for arr1: " << sol.getSecondLargest(arr1) << endl; // 34
    cout << "Output for arr2: " << sol.getSecondLargest(arr2) << endl; // 5
    cout << "Output for arr3: " << sol.getSecondLargest(arr3) << endl; // -1

    return 0;
}
