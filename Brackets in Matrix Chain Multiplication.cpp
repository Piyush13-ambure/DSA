/*Given an array arr[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is arr[i] * arr[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also, please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "true" for the correct string and "false" for the incorrect string. You need to only return a string that performs a minimum number of multiplications*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, 0));

        // dp[i][j] = Minimum number of scalar multiplications needed to multiply matrices from i to j

        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        string result;
        int nameIndex = 0;
        buildOrder(1, n - 1, bracket, result, nameIndex);
        return result;
    }

private:
    void buildOrder(int i, int j, vector<vector<int>> &bracket, string &res, int &nameIndex) {
        if (i == j) {
            res += (char)('A' + nameIndex++);
            return;
        }
        res += '(';
        buildOrder(i, bracket[i][j], bracket, res, nameIndex);
        buildOrder(bracket[i][j] + 1, j, bracket, res, nameIndex);
        res += ')';
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr1 = {40, 20, 30, 10, 30};
    vector<int> arr2 = {10, 20, 30};
    vector<int> arr3 = {3, 3, 3};

    cout << (sol.matrixChainOrder(arr1) == "((A(BC))D)" ? "true" : "false") << endl;
    cout << (sol.matrixChainOrder(arr2) == "(AB)" ? "true" : "false") << endl;
    cout << (sol.matrixChainOrder(arr3) == "(AB)" ? "true" : "false") << endl;

    return 0;
}
