//Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

//Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;  // No next permutation for arrays with size 1 or less
        
        // Step 1: Find the first decreasing element from the end
        int i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        // Step 2: If such an element exists, find the next larger element and swap
        if (i >= 0) {
            int j = n - 1;
            while (arr[j] <= arr[i]) {
                j--;
            }
            swap(arr[i], arr[j]);
        }

        // Step 3: Reverse the part after i to get the smallest lexicographical order
        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3};
    
    solution.nextPermutation(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
