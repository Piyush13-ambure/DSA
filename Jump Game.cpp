//Given a array of positive integers arr, where each element denotes the maximum length of jump you can cover. Find out if you can make it to the last index starting from the first index of the list, return true if you can reach the last index.



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int> &arr) {
        int maxReach = 0; // Maximum index we can reach

        for (int i = 0; i < arr.size(); i++) {
            if (i > maxReach) return false; // If current index is unreachable, return false
            maxReach = max(maxReach, i + arr[i]); // Update max reach

            if (maxReach >= arr.size() - 1) return true; // If we can reach the last index, return true
        }

        return false;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 2, 0, 3, 0, 0};
    cout << (sol.canReach(arr1) ? "true" : "false") << endl; // Output: true
    
    vector<int> arr2 = {1, 0, 2};
    cout << (sol.canReach(arr2) ? "true" : "false") << endl; // Output: false

    return 0;
}
