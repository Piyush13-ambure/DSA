//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Base case: No input digits
        
        // Mapping of digits to letters
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result;
        string current;
        backtrack(digits, keypad, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &digits, const vector<string> &keypad, int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = keypad[digits[index] - '0'];  // Get the corresponding letters for the digit
        for (char letter : letters) {
            current.push_back(letter);   // Choose a letter
            backtrack(digits, keypad, index + 1, current, result);  // Recur for the next digit
            current.pop_back();  // Undo choice (backtrack)
        }
    }
};

// Main function to test the solution
int main() {
    Solution obj;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);
    
    cout << "Possible letter combinations: ";
    for (const string &combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    
    return 0;
}
