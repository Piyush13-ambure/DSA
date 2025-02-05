//Given an array A[] of N integers and an integer M. The task is to count the number of subarrays which have median M.
Median of an array is defined as below:

//1. If N is odd, the median value is the number that is in the middle after sorting the array.
//2. if N is even, the median value is the left of the two middle numbers after sorting the array. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarray(int N, vector<int> A, int M) {
        unordered_map<int, int> balanceCount;
        int balance = 0, medianIndex = -1;
        long long count = 0;

        // Step 1: Identify where M is in the array
        for (int i = 0; i < N; i++) {
            if (A[i] == M) {
                medianIndex = i;
                break;
            }
        }

        // Step 2: Traverse from median index and maintain balance
        for (int i = 0; i < N; i++) {
            if (A[i] > M) balance++;
            else if (A[i] < M) balance--;

            // If we have reached the median, reset balanceCount and mark this as 0-balance
            if (i >= medianIndex) {
                count += balanceCount[balance] + balanceCount[balance - 1];
            } else {
                balanceCount[balance]++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    cout << obj.countSubarray(5, {2, 1, 3, 5, 4}, 2) << endl; // Output: 3
    cout << obj.countSubarray(1, {1}, 1) << endl;             // Output: 1
    return 0;
}
