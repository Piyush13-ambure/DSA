//Given an array A[] consisting of 0’s and 1’s. A flip operation is one in which you turn 1 into 0 and a 0 into 1. You have to do at most one “Flip” operation of any subarray. Formally, select a range (l, r) in the array A[], such that (0 ≤ l ≤ r < n) holds and flip the elements in this range to get the maximum ones in the final array. You can possibly make zero operations to get the answer. You are asked to return the maximum number of 1 you can get in the array after doing flip operation.


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxOnes(int A[], int N)
    {
        int totalOnes = 0;
        int maxDiff = 0, currDiff = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] == 1) {
                totalOnes++;  // Count total 1s
            }

            // Convert to difference array: (0 -> +1), (1 -> -1)
            int value = (A[i] == 0) ? 1 : -1;

            // Apply Kadane's Algorithm
            currDiff = max(value, currDiff + value);
            maxDiff = max(maxDiff, currDiff);
        }

        // If all elements were 1s, flipping any would decrease count
        return (totalOnes == N) ? N - 1 : totalOnes + maxDiff;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.maxOnes(A, n) << endl;
    }
    return 0;
}
