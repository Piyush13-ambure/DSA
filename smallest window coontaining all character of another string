// Given two strings s1 and s2. Find the smallest window in the string s1 consisting of all the characters(including duplicates) of the string s2. Return "" in case no such window is present. If there are multiple such windows of the same length, return the one with the least starting index.#include <iostream>

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the smallest window in the string s1 consisting of all characters of string s2
    string smallestWindow(string& s1, string& s2) {
        unordered_map<char, int> freqMap; // Frequency map for characters in s2
        for (char c : s2) {
            freqMap[c]++;
        }

        int required = freqMap.size(); // Number of unique characters in s2 to be matched
        int left = 0, right = 0;
        int formed = 0; // Number of characters in s2 matched with their frequency in the current window
        unordered_map<char, int> windowCounts; // Frequency map for characters in the current window
        int minLen = INT_MAX, startIdx = 0; // Variables to track the smallest window

        while (right < s1.size()) {
            char c = s1[right];
            windowCounts[c]++;

            // Check if the current character satisfies the condition for matching
            if (freqMap.count(c) && windowCounts[c] == freqMap[c]) {
                formed++;
            }

            // Try to minimize the window size while it still satisfies the condition
            while (left <= right && formed == required) {
                c = s1[left];

                // Update the smallest window if needed
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Remove the leftmost character and update the window counts
                windowCounts[c]--;
                if (freqMap.count(c) && windowCounts[c] < freqMap[c]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        // If no valid window is found, return an empty string
        return minLen == INT_MAX ? "" : s1.substr(startIdx, minLen);
    }
};

// Main function to test the Solution class
int main() {
    string s1, s2;
    cout << "Enter the first string (s1): ";
    cin >> s1;
    cout << "Enter the second string (s2): ";
    cin >> s2;

    Solution solution;
    string result = solution.smallestWindow(s1, s2);

    if (result.empty()) {
        cout << "No such window exists.\n";
    } else {
        cout << "The smallest window in s1 containing all characters of s2 is: " << result << endl;
    }

    return 0;
}
