//An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

//You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) // Same parity
                return false;
        }
        return true;
    }
};

// Main function to test the implementation
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    if (obj.isArraySpecial(nums))
        cout << "The array is special.\n";
    else
        cout << "The array is NOT special.\n";

    return 0;
}
