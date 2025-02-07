//Given an array A[] of N integers and a range(L, R). The task is to find the number of subarrays having sum in the range L to R (inclusive).


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count subarrays with sum in range [L, R]
    long long countSubarray(int N, vector<int> A, long long L, long long R) {
        return countAtMost(A, R) - countAtMost(A, L - 1);
    }

  private:
    // Helper function to count subarrays with sum at most `limit`
    long long countAtMost(vector<int>& A, long long limit) {
        if (limit < 0) return 0;  // No valid subarray if limit is negative
        long long count = 0, sum = 0;
        int left = 0;
        
        for (int right = 0; right < A.size(); right++) {
            sum += A[right];  // Expand window by adding A[right]
            
            // Shrink window if sum exceeds the limit
            while (sum > limit) {
                sum -= A[left];
                left++;
            }
            
            // All subarrays ending at `right` and starting from `left` to `right` are valid
            count += (right - left + 1);
        }
        return count;
    }
};

// Main function to test the solution
int main() {
    Solution obj;
    
    // Example 1
    int N1 = 3, L1 = 3, R1 = 8;
    vector<int> A1 = {1, 4, 6};
    cout << obj.countSubarray(N1, A1, L1, R1) << endl;  // Output: 3
    
    // Example 2
    int N2 = 4, L2 = 4, R2 = 13;
    vector<int> A2 = {2, 3, 5, 8};
    cout << obj.countSubarray(N2, A2, L2, R2) << endl;  // Output: 6
    
    return 0;
}
