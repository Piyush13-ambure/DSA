/*Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Step 1: Sort both arrays in descending order
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        // Max heap to store (sum, i, j)
        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> visited;
        vector<int> result;

        // Step 2: Insert the first pair (largest elements)
        maxHeap.push({A[0] + B[0], 0, 0});
        visited.insert({0, 0});

        // Step 3: Extract K largest sums
        while (K-- && !maxHeap.empty()) {
            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();
            result.push_back(sum);

            // Next potential candidates
            if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
                maxHeap.push({A[i + 1] + B[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            if (j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
                maxHeap.push({A[i] + B[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    int N, K;
    cout << "Enter N and K: ";
    cin >> N >> K;

    vector<int> A(N), B(N);
    cout << "Enter elements of array A: ";
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; i++) cin >> B[i];

    Solution obj;
    vector<int> result = obj.maxCombinations(N, K, A, B);

    cout << "Top " << K << " sum combinations: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
