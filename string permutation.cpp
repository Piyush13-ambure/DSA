//Given a string S. The task is to find all permutations (need not be different) of a given string.

//Note: return the permutations in lexicographically increasing order.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(string &S, vector<string> &result, string &current, vector<bool> &visited) {
        if (current.size() == S.size()) {
            result.push_back(current);  // If the current string is a valid permutation, add to the result
            return;
        }
        
        for (int i = 0; i < S.size(); i++) {
            // Skip the character if it is already used in the current position
            // and also avoid using the same character in the same position
            if (visited[i] || (i > 0 && S[i] == S[i - 1] && !visited[i - 1])) {
                continue;
            }
            
            visited[i] = true;
            current.push_back(S[i]);
            backtrack(S, result, current, visited);  // Recurse with the current character included
            visited[i] = false;  // Backtrack
            current.pop_back();  // Remove the last character
        }
    }

    vector<string> permutation(string S) {
        vector<string> result;
        string current;
        vector<bool> visited(S.size(), false);
        
        // Sort the string to ensure lexicographically increasing order
        sort(S.begin(), S.end());
        
        backtrack(S, result, current, visited);
        
        return result;
    }
};

int main() {
    Solution sol;
    string S;
    cout << "Enter the string: ";
    cin >> S;
    
    vector<string> result = sol.permutation(S);
    
    cout << "Permutations in lexicographically increasing order:" << endl;
    for (const string &s : result) {
        cout << s << endl;
    }
    
    return 0;
}
