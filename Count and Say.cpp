/*The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  // Base case
        
        string result = "1";  // Start from "1"
        
        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;
            
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;  // Count the repeated characters
                } else {
                    current += to_string(count) + result[j - 1]; // Append count and digit
                    count = 1;
                }
            }
            current += to_string(count) + result.back();  // Append last sequence
            
            result = current;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    cout << "Output: " << sol.countAndSay(n) << endl;  // Expected Output: "1211"
    return 0;
}
