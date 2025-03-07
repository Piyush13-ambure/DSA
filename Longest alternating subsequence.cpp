/*You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

Note: A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int alternatingMaxLength(vector<int>& arr) {
        if (arr.empty()) return 0;

        int up = 1, down = 1; // Start with a sequence of length 1
        
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                up = down + 1;
            } else if (arr[i] < arr[i - 1]) {
                down = up + 1;
            }
        }
        
        return max(up, down);
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    vector<int> arr1 = {1, 5, 4};
    vector<int> arr2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    cout << "Output for arr1: " << sol.alternatingMaxLength(arr1) << endl;
    cout << "Output for arr2: " << sol.alternatingMaxLength(arr2) << endl;

    return 0;
}
