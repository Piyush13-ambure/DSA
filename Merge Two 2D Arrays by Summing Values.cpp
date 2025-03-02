/*You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) { // Same id, sum values
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++, j++;
            } 
            else if (nums1[i][0] < nums2[j][0]) { // nums1 has smaller id
                result.push_back(nums1[i]);
                i++;
            } 
            else { // nums2 has smaller id
                result.push_back(nums2[j]);
                j++;
            }
        }

        // Append remaining elements if any
        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};

// **Main Function**
int main() {
    Solution obj;

    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};

    vector<vector<int>> result = obj.mergeArrays(nums1, nums2);

    for (auto& row : result) {
        cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;

    return 0;
}
