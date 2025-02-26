/*Given a sorted array of unique elements in increasing order, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> result;

        // Binary search to find the closest position of x
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                break;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Pointers for closest elements
        int l = mid, r = mid;
        
        // If x is found in the array, move l to left
        if (arr[mid] == x) {
            l--;
        }

        // Finding K closest elements
        while (k > 0) {
            if (l >= 0 && r < n) {
                int leftDiff = abs(arr[l] - x);
                int rightDiff = abs(arr[r] - x);

                if (leftDiff < rightDiff || (leftDiff == rightDiff && arr[l] > arr[r])) {
                    result.push_back(arr[l--]);
                } else {
                    result.push_back(arr[r++]);
                }
            } else if (l >= 0) {  // Only left side available
                result.push_back(arr[l--]);
            } else {  // Only right side available
                result.push_back(arr[r++]);
            }
            k--;
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    vector<int> arr1 = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int n1 = arr1.size();
    int k1 = 4, x1 = 35;
    vector<int> res1 = sol.printKClosest(arr1, n1, k1, x1);
    for (int num : res1) cout << num << " ";
    cout << endl; // Output: 39 30 42 45

    vector<int> arr2 = {1, 2, 3, 6, 10};
    int n2 = arr2.size();
    int k2 = 3, x2 = 4;
    vector<int> res2 = sol.printKClosest(arr2, n2, k2, x2);
    for (int num : res2) cout << num << " ";
    cout << endl; // Output: 3 6 2

    return 0;
}
