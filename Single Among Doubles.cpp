//Given a sorted array arr[] of n positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.


#include <iostream>
using namespace std;

class Solution {
public:
    int search(int n, int arr[]) {
        int low = 0, high = n - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even for pair checking
            if (mid % 2 == 1) {
                mid--;
            }
            
            // If the next element is the same, move right
            if (arr[mid] == arr[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        
        return arr[low];  // The single element
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    int arr1[] = {1, 1, 2, 5, 5};
    int n1 = 5;
    cout << "Output: " << sol.search(n1, arr1) << endl;

    int arr2[] = {2, 2, 5, 5, 20, 30, 30};
    int n2 = 7;
    cout << "Output: " << sol.search(n2, arr2) << endl;

    return 0;
}
