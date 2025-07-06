/*You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2; // frequency map for nums2 elements

public:
    // Constructor
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    // Adds val to nums2[index]
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;         // Remove old occurrence
        nums2[index] += val;
        freq2[nums2[index]]++;   // Add new occurrence
    }

    // Counts pairs where nums1[i] + nums2[j] == tot
    int count(int tot) {
        int res = 0;
        for (int num1 : nums1) {
            int complement = tot - num1;
            if (freq2.count(complement)) {
                res += freq2[complement];
            }
        }
        return res;
    }
};

// Example main function
int main() {
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs findSumPairs(nums1, nums2);

    cout << findSumPairs.count(7) << endl; // 8
    findSumPairs.add(3, 2);                // nums2 = [1,4,5,4,5,4]
    cout << findSumPairs.count(8) << endl; // 2
    cout << findSumPairs.count(4) << endl; // 1
    findSumPairs.add(0, 1);                // nums2 = [2,4,5,4,5,4]
    findSumPairs.add(1, 1);                // nums2 = [2,5,5,4,5,4]
    cout << findSumPairs.count(7) << endl; // 11

    return 0;
}
