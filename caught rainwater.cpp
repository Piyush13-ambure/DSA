//Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
//  main.cpp
//  traping rain water
//
//  Created by piyush ambure on 12/01/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = sizeof(arr);
        if (n < 3) return 0; // Less than 3 blocks can't trap any water

        int left = 0, right = n - 1; // Two pointers
        int leftMax = 0, rightMax = 0; // To track maximum heights on the left and right
        int water = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                // Process left side
                if (arr[left] >= leftMax) {
                    leftMax = arr[left]; // Update left max
                } else {
                    water += leftMax - arr[left]; // Calculate trapped water
                }
                left++;
            } else {
                // Process right side
                if (arr[right] >= rightMax) {
                    rightMax = arr[right]; // Update right max
                } else {
                    water += rightMax - arr[right]; // Calculate trapped water
                }
                right--;
            }
        }

        return water;
    }
};

int main() {
    int n;
    cout << "Enter the number of blocks: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the heights of the blocks: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.maxWater(arr);

    cout << "Maximum water that can be trapped: " << result << endl;

    return 0;
}
