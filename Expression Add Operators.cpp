//Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string& S, int target, int index, long currentValue, long prevOperand, string expr) {
        // Base Case: If we have used all digits in S
        if (index == S.size()) {
            if (currentValue == target) {
                result.push_back(expr);
            }
            return;
        }

        // Try different operand lengths (1 to remaining size)
        for (int i = index; i < S.size(); i++) {
            string numStr = S.substr(index, i - index + 1);
            long num = stol(numStr);

            // Prevent numbers with leading zeros
            if (numStr.size() > 1 && numStr[0] == '0') break;

            if (index == 0) {
                // First number, no operator needed
                backtrack(result, S, target, i + 1, num, num, numStr);
            } else {
                // Try addition
                backtrack(result, S, target, i + 1, currentValue + num, num, expr + "+" + numStr);

                // Try subtraction
                backtrack(result, S, target, i + 1, currentValue - num, -num, expr + "-" + numStr);

                // Try multiplication
                backtrack(result, S, target, i + 1, (currentValue - prevOperand) + (prevOperand * num), prevOperand * num, expr + "*" + numStr);
            }
        }
    }

    vector<string> addOperators(string S, int target) {
        vector<string> result;
        if (S.empty()) return result;
        backtrack(result, S, target, 0, 0, 0, "");
        return result;
    }
};

int main() {
    Solution obj;
    string S;
    int target;
    
    cin >> S >> target;
    
    vector<string> expressions = obj.addOperators(S, target);
    
    for (const string& expr : expressions) {
        cout << expr << endl;
    }

    return 0;
}
