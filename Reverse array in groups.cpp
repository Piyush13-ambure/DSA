/*Given an array arr[] of positive integers. Reverse every sub-array group of size k.
Note: If at any instance, k is greater or equal to the array size, then reverse the entire array. */
class Solution {
  public:
    void reverseInGroups(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i += k) {
            // Determine the end point for the current sub-array.
            int end = min(i + k, n);
            // Reverse the sub-array from arr[i] to arr[end - 1].
            reverse(arr.begin() + i, arr.begin() + end);
        }
    }
};
