//Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int low = 0, high = n;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = n - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : arr2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2) + min(right1, right2);
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        
        return -1; // Should never reach here
    }
};

int main() {
    vector<int> arr1 = {1, 2, 4, 6, 10};
    vector<int> arr2 = {4, 5, 6, 9, 12};

    Solution sol;
    cout << sol.SumofMiddleElements(arr1, arr2) << endl; // Output: 11

    vector<int> arr3 = {1, 12, 15, 26, 38};
    vector<int> arr4 = {2, 13, 17, 30, 45};
    
    cout << sol.SumofMiddleElements(arr3, arr4) << endl; // Output: 32

    return 0;
}
