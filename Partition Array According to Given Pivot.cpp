/*You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        
        // Classify elements
        for (int num : nums) {
            if (num < pivot)
                less.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                greater.push_back(num);
        }
        
        // Concatenate the three lists
        vector<int> result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());
        
        return result;
    }
};

// Main function
int main() {
    vector<int> nums;
    int n, pivot;

    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter the elements of the array: ";
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter the pivot value: ";
    cin >> pivot;

    Solution sol;
    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Output: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
