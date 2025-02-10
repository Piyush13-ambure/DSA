//Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (left < right) {
            if (arr[left] < arr[right]) {
                if (arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    water += leftMax - arr[left];
                left++;
            } else {
                if (arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    water += rightMax - arr[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    vector<int> arr1 = {3, 0, 1, 0, 4, 0, 2};
    vector<int> arr2 = {3, 0, 2, 0, 4};
    vector<int> arr3 = {1, 2, 3, 4};
    vector<int> arr4 = {2, 1, 5, 3, 1, 0, 4};

    Solution sol;
    cout << "Water trapped: " << sol.maxWater(arr1) << endl; // Output: 10
    cout << "Water trapped: " << sol.maxWater(arr2) << endl; // Output: 7
    cout << "Water trapped: " << sol.maxWater(arr3) << endl; // Output: 0
    cout << "Water trapped: " << sol.maxWater(arr4) << endl; // Output: 9

    return 0;
}
