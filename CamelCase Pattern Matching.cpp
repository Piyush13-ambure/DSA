/*Given a dictionary of words arr[] where each word follows CamelCase notation, print all words in the dictionary that match with a given pattern pat consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.
Example: "GeeksForGeeks" matches the pattern "GFG", because if we combine all the capital letters in "GeeksForGeeks" they become "GFG". Also note "GeeksForGeeks" matches with the pattern "GFG" and also "GF", but does not match with "FG".

Note: The driver code will sort your answer before checking and return the answer in any order.*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        vector<string> result;

        for (const string &word : arr) {
            string upperCaseChars;
            
            // Extract uppercase characters
            for (char ch : word) {
                if (isupper(ch)) {
                    upperCaseChars += ch;
                }
            }
            
            // Check if the extracted uppercase sequence matches the pattern
            if (upperCaseChars.find(pat) == 0) { // Ensures it starts with 'pat'
                result.push_back(word);
            }
        }
        
        return result;
    }
};

// Driver function
int main() {
    vector<string> arr = {"WelcomeGeek", "WelcomeToGeeksForGeeks", "GeeksForGeeks"};
    string pat = "WTG";
    
    Solution obj;
    vector<string> res = obj.camelCase(arr, pat);
    
    if (res.empty()) {
        cout << "[]" << endl;
    } else {
        for (const string &str : res) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
