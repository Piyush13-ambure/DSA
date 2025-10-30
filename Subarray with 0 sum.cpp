/*Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. */

class Solution {
  public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // using map to store the prefix sum which has appeared already.
        unordered_map<int, bool> sumMap;

        int sum = 0;
        int n = arr.size();
        // iterating over the array.
        for (int i = 0; i < n; i++) {
            // storing prefix sum.
            sum += arr[i];

            // if prefix sum is 0 or if it is already present in map then it is
            // repeated which means there is a subarray whose summation is 0,
            // so we return true.
            if (sum == 0 || sumMap[sum] == true)
                return true;

            // storing true in map for every prefix sum obtained.
            sumMap[sum] = true;
        }
        // returning false if we don't get any subarray with 0 sum.
        return false;
    }
};
