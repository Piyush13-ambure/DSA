//Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
//Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_set<int> bSet(B, B + M);  // Store B[] elements for quick lookup
        vector<int> filteredA;

        // Step 1: Filter A[] to keep only elements present in B[]
        for (int i = 0; i < N; i++) {
            if (bSet.find(A[i]) != bSet.end()) {
                filteredA.push_back(A[i]);
            }
        }

        // Step 2: Find LIS of filtered A[] in terms of B[]
        vector<int> lis;
        for (int x : filteredA) {
            auto it = lower_bound(lis.begin(), lis.end(), x); // Find position
            if (it == lis.end()) lis.push_back(x);  // Append to LIS
            else *it = x;  // Replace with smaller value
        }

        int lcsLength = lis.size(); // LIS length is LCS length
        int deletions = N - lcsLength;  // Remove elements not in LCS
        int insertions = M - lcsLength; // Insert missing elements from B[]

        return deletions + insertions;
    }
};

// Driver function
int main() {
    Solution sol;
    int A1[] = {1, 2, 5, 3, 1};
    int B1[] = {1, 3, 5};
    cout << sol.minInsAndDel(A1, B1, 5, 3) << endl; // Output: 4

    int A2[] = {1, 4};
    int B2[] = {1, 4};
    cout << sol.minInsAndDel(A2, B2, 2, 2) << endl; // Output: 0

    return 0;
}

