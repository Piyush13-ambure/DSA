//Given two arrays arr1[] and arr2[]. Find number of pairs such that xy > yx where x is an element from arr1[] and y is an element from arr2[]. Returns an integer denoting the number of pairs that are true to the given condition. 



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to count pairs (x, y) where x^y > y^x
    long long countPairs(vector<int>& arr1, vector<int>& arr2) {
        // Sort arr2 to allow binary search
        sort(arr2.begin(), arr2.end());

        // Precompute counts of 0, 1, 2, 3, 4 in arr2 for special handling
        int countZero = 0, countOne = 0, countTwo = 0, countThree = 0, countFour = 0;
        for (int y : arr2) {
            if (y == 0) countZero++;
            else if (y == 1) countOne++;
            else if (y == 2) countTwo++;
            else if (y == 3) countThree++;
            else if (y == 4) countFour++;
        }

        long long totalPairs = 0;
        
        // Process each element x in arr1
        for (int x : arr1) {
            if (x == 0) continue; // x^y = 0, which is never > y^x
            if (x == 1) {
                totalPairs += countZero; // 1^y > y^1 only when y = 0
                continue;
            }

            // Find number of elements in arr2 greater than x using binary search
            int idx = upper_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            int countGreater = arr2.size() - idx;
            totalPairs += countGreater;

            // Add count of y = 0 and y = 1 since x^y > y^x when y = 0,1
            totalPairs += countZero + countOne;

            // Special cases:
            if (x == 2) {
                // Subtract the cases where y = 3 and y = 4 (as 2^3 < 3^2 and 2^4 < 4^2)
                totalPairs -= (countThree + countFour);
            }
            if (x == 3) {
                // Add countTwo (as 3^2 > 2^3)
                totalPairs += countTwo;
            }
        }

        return totalPairs;
    }
};

// Main function to test the solution
int main() {
    vector<int> arr1 = {2, 1, 6};
    vector<int> arr2 = {1, 5};
    
    Solution sol;
    cout << "Number of valid pairs: " << sol.countPairs(arr1, arr2) << endl;

    return 0;
}
