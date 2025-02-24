//Given an integer array of N elements. You need to find the maximum sum of two elements such that sum is closest to zero.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestToZero(int arr[], int n) {
        // Sort the array to use two-pointer approach
        sort(arr, arr + n);
        
        int left = 0, right = n - 1;
        int closestSum = INT_MAX; // To store closest sum
        int maxClosestSum = INT_MIN; // To store the maximum of closest sums
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            // If this sum is closer to zero, update closestSum and maxClosestSum
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                maxClosestSum = sum; // New closest sum
            }
            // If we find another sum equally close to zero, take the maximum
            else if (abs(sum) == abs(closestSum)) {
                maxClosestSum = max(maxClosestSum, sum);
            }
            
            // Move pointers based on sum value
            if (sum < 0)
                left++; // Move left forward to increase sum
            else
                right--; // Move right backward to decrease sum
        }
        
        return maxClosestSum;
    }
};

// Main function to test the program
int main() {
    int N;
    cout << "Enter number of elements: ";
    cin >> N;
    
    int arr[N];
    cout << "Enter elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    Solution obj;
    int result = obj.closestToZero(arr, N);
    cout << "Maximum sum closest to zero: " << result << endl;

    return 0;
}
