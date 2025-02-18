/*Given a sorted array arr[]. Find the element that appears only once in the array. All other elements appear exactly twice. 

You solution must run in O(log n) time and O(1) space.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findOnce(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even for checking pairs
            if (mid % 2 == 1) mid--;

            // If mid and mid+1 are the same, the single element is on the right
            if (arr[mid] == arr[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }

        return arr[low]; // The single element
    }
};

// **Main function to test the code**
int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65};
    cout << "Unique Element: " << sol.findOnce(arr) << endl;
    
    vector<int> arr2 = {5};
    cout << "Unique Element: " << sol.findOnce(arr2) << endl;

    vector<int> arr3 = {1, 2, 2, 3, 3};
    cout << "Unique Element: " << sol.findOnce(arr3) << endl;

    return 0;
}
