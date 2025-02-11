//You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

//Note: The answer should be returned in an increasing format.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        // Step 1: Find potential candidates
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the candidates
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        // Step 3: Return result in increasing order
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> result1 = sol.findMajority(arr1);
    cout << "Output: ";
    for (int num : result1) cout << num << " ";
    cout << endl; // Expected Output: [5, 6]

    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> result2 = sol.findMajority(arr2);
    cout << "Output: ";
    for (int num : result2) cout << num << " ";
    cout << endl; // Expected Output: []

    return 0;
}

