//Given a string str of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. Return the minimum possible required value.



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minValue(string s, int k) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Max heap (priority queue) to prioritize largest frequency first
        priority_queue<int> pq;
        for (auto it : freq) {
            pq.push(it.second);
        }

        // Step 3: Remove k characters by reducing the highest frequency counts
        while (k > 0 && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            top--;  // Reduce the highest frequency character
            k--;
            if (top > 0) {
                pq.push(top);
            }
        }

        // Step 4: Compute the sum of squares of remaining frequencies
        int result = 0;
        while (!pq.empty()) {
            int count = pq.top();
            pq.pop();
            result += count * count;
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    cout << "Output: " << sol.minValue("abccc", 1) << endl; // Expected: 6
    cout << "Output: " << sol.minValue("aabcbcbcabcc", 3) << endl; // Expected: 27
    return 0;
}
