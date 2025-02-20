//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string> &result, string current, int openCount, int closeCount, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (openCount < n)
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        
        if (closeCount < openCount)
            backtrack(result, current + ")", openCount, closeCount + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    int n = 3;
    vector<string> res = sol.generateParenthesis(n);

    for (string s : res) 
        cout << s << endl;

    return 0;
}
