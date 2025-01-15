//Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
//  main.cpp
//  longest consecutive subsequence
//
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to return length of longest subsequence of consecutive integers
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end()); // Store all elements in a set
        int longest = 0;

        // Iterate through the array
        for (int num : arr) {
            // Check if this is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the maximum length
                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(arr);
    cout << "Length of the longest consecutive subsequence: " << result << endl; // Output: 4
    return 0;
}
