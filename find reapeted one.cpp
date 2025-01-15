//Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

//NOTE:
//1. You need to find the answer for every i (0 <= i < n)
//2. In order to find the solution for every you need to consider the string from starting position till the ith position.
//  main.m
//  stream first non repeatative
//
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in the stream
    string FirstNonRepeating(string &s) {
        queue<char> q;          // Queue to track the order of characters
        vector<int> freq(26, 0); // Frequency array for lowercase letters
        string result = "";     // Resultant string to store the answer
        
        for (char ch : s) {
            // Update the frequency of the character
            freq[ch - 'a']++;
            
            // Push the character into the queue
            q.push(ch);
            
            // Check the queue's front for the first non-repeating character
            while (!q.empty()) {
                if (freq[q.front() - 'a'] > 1) {
                    // If the frequency of the front character is more than 1, remove it
                    q.pop();
                } else {
                    // Found the first non-repeating character
                    result += q.front();
                    break;
                }
            }
            
            // If the queue becomes empty, no non-repeating character exists
            if (q.empty()) {
                result += '#';
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "aabc";
    string result = sol.FirstNonRepeating(s);
    cout << "Output: " << result << endl; // Expected Output: "a#bb"
    return 0;
}
