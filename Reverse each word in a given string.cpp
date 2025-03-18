/*You are given a string s. You need to reverse each word in it where the words are separated by spaces and return the modified string.

Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.

*/

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        stringstream ss(s);
        string word, result;
        
        while (ss >> word) { // Extract words ignoring extra spaces
            reverse(word.begin(), word.end()); // Reverse each word
            if (!result.empty()) result += " "; // Add space if not first word
            result += word;
        }
        
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    string s1 = "  i like this program very much  ";
    cout << "\"" << sol.reverseWords(s1) << "\"" << endl; // Output: "i ekil siht margorp yrev hcum"

    string s2 = "  pqr mno   ";
    cout << "\"" << sol.reverseWords(s2) << "\"" << endl; // Output: "rqp onm"

    string s3 = "pqr";
    cout << "\"" << sol.reverseWords(s3) << "\"" << endl; // Output: "rqp"

    return 0;
}
