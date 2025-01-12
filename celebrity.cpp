//A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
//  main.cpp
//  celebrity problem
//
//  Created by piyush ambure on 12/01/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return -1;

        // Step 1: Find a potential celebrity
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[candidate][i] == 1) {
                // If candidate knows i, candidate can't be a celebrity
                candidate = i;
            }
        }

        // Step 2: Verify if the candidate is a celebrity
        for (int i = 0; i < n; ++i) {
            if (i != candidate) {
                // Check if the candidate knows i or i does not know the candidate
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1; // Candidate is not a celebrity
                }
            }
        }

        return candidate; // Candidate is a celebrity
    }
};

int main() {
    int n;
    cout << "Enter the number of people at the party: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " matrix (0 or 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    int result = sol.celebrity(mat);

    if (result == -1) {
        cout << "No celebrity at the party.\n";
    } else {
        cout << "The celebrity is at index: " << result << endl;
    }

    return 0;
}
