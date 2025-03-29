//Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_set<int> seen;  // Track unique numbers
        unordered_set<int> duplicates;  // Track duplicates
        
        for (int num : arr) {
            if (seen.count(num)) {  // If already seen, it's a duplicate
                duplicates.insert(num);
            } else {
                seen.insert(num);
            }
        }
        
        return vector<int>(duplicates.begin(), duplicates.end());
    }
};

int main() {
    Solution solution;
    
    vector<int> arr1 = {2, 3, 1, 2, 3};
    vector<int> result1 = solution.findDuplicates(arr1);
    cout << "Output: ";
    for (int num : result1) cout << num << " "; // Expected: [2, 3]
    cout << endl;

    vector<int> arr2 = {0, 3, 1, 2};
    vector<int> result2 = solution.findDuplicates(arr2);
    cout << "Output: ";
    for (int num : result2) cout << num << " "; // Expected: []
    cout << endl;

    vector<int> arr3 = {2};
    vector<int> result3 = solution.findDuplicates(arr3);
    cout << "Output: ";
    for (int num : result3) cout << num << " "; // Expected: []
    cout << endl;

    return 0;
}
