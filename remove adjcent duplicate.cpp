#Given a string s, remove all its adjacent duplicate characters recursively, until there are no adjacent duplicate characters left.

#Note: If the resultant string becomes empty, return an empty string.


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to recursively remove adjacent duplicates
    string removeUtil(string &s) {
        bool changed = false;
        int n = s.length();
        
        // Step 1: Iterate through the string and remove adjacent duplicates
        string result = "";
        for (int i = 0; i < n; i++) {
            // If this is the first character or no duplicate with previous character
            if (i == 0 || s[i] != s[i - 1]) {
                result += s[i];
            } else {
                changed = true;  // Mark that we found a duplicate pair
            }
        }
        
        // If no changes were made, return the result
        if (!changed) return result;
        
        // Step 2: Recursively call the function on the result to remove new duplicates
        return removeUtil(result);
    }
};

int main() {
    Solution solution;
    string s = "aaabccddd";
    cout << "Result: " << solution.removeUtil(s) << endl;  // Output should be "ab"
    
    return 0;
}
