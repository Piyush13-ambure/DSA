/*Given an array arr[], where arr[i] denotes the number of characters in one word. Let k be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

*/


#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to find the minimum cost of word wrapping.
    int solveWordWrap(vector<int> arr, int k) {
        int n = arr.size();
        int i, j;
        int currlen;
        int cost;

        // Initializing dp and ans vectors.
        vector<int> dp(n, 0);
        vector<int> ans(n, 0);
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;

        // Calculating dp values from right to left.
        for (i = n - 2; i >= 0; i--) {
            currlen = -1;
            dp[i] = INT_MAX;

            // Calculating cost for current line wrappings.
            for (j = i; j < n; j++) {
                currlen += (arr[j] + 1);

                // If current line length exceeds the limit, break.
                if (currlen > k)
                    break;

                // Calculating cost for current wrapping.
                if (j == n - 1)
                    cost = 0;
                else
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];

                // Updating dp and ans vectors.
                if (cost < dp[i]) {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        int res = 0;
        i = 0;

        // Calculating final result by summing up the costs.
        while (i < n) {
            int pos = 0;

            // Calculating positions for current line wrappings.
            for (int j = i; j < ans[i] + 1; j++) {
                pos += arr[j];
            }

            // Calculating cost of extra spaces.
            int x = ans[i] - i;
            if (ans[i] + 1 != arr.size())
                res += (k - x - pos) * (k - x - pos);

            // Updating i to next line wrapping.
            i = ans[i] + 1;
        }

        // Returning the final result.
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while (ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
