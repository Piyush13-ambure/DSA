/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0); // Count occurrences of 'a', 'b', and 'c'
        int left = 0, result = 0;
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++; // Increment count of current character

            // Shrink the window while it contains all three characters
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.size() - right; // Count valid substrings
                count[s[left] - 'a']--; // Move left pointer
                left++;
            }
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "abcabc";
    cout << "Output: " << sol.numberOfSubstrings(s1) << endl; // Expected: 10

    string s2 = "aaacb";
    cout << "Output: " << sol.numberOfSubstrings(s2) << endl; // Expected: 3

    string s3 = "abc";
    cout << "Output: " << sol.numberOfSubstrings(s3) << endl; // Expected: 1

    return 0;
}
