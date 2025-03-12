//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0, water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];  // Update left max
                } else {
                    water += left_max - height[left];  // Calculate trapped water
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];  // Update right max
                } else {
                    water += right_max - height[right];  // Calculate trapped water
                }
                right--;
            }
        }
        
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height1) << endl;  // Output: 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << sol.trap(height2) << endl;  // Output: 9

    return 0;
}
