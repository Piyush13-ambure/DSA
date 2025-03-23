/*Find the missing element from an ordered array arr[], elements of array arr representing an Arithmetic Progression(AP).

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. Boundary elements (first and last elements) are not missing.*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n; // Common difference
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if missing element is before mid
            if (mid > 0 && arr[mid] - arr[mid - 1] != d) {
                return arr[mid - 1] + d;
            }
            
            // Check if missing element is after mid
            if (mid < n - 1 && arr[mid + 1] - arr[mid] != d) {
                return arr[mid] + d;
            }
            
            // Adjust search range
            if (arr[mid] == arr[0] + mid * d) {
                low = mid + 1;  // Move right
            } else {
                high = mid - 1; // Move left
            }
        }
        
        return -1; // Should never reach here
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {2, 4, 8, 10, 12, 14};
    cout << "Missing element: " << sol.findMissing(arr1) << endl;  // Output: 6
    
    vector<int> arr2 = {1, 6, 11, 16, 21, 31};
    cout << "Missing element: " << sol.findMissing(arr2) << endl;  // Output: 26
    
    return 0;
}
