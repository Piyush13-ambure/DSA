/*A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();

        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            if (part.length() < k) {
                part.append(k - part.length(), fill);  // Fill with fill char
            }
            result.push_back(part);
        }

        return result;
    }
};

// Helper function to print the result
void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"";
        if (i != vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abcdefghi";
    int k1 = 3;
    char fill1 = 'x';
    vector<string> res1 = sol.divideString(s1, k1, fill1);
    cout << "Output 1: ";
    printVector(res1);  // Output: ["abc", "def", "ghi"]

    // Test Case 2
    string s2 = "abcdefghij";
    int k2 = 3;
    char fill2 = 'x';
    vector<string> res2 = sol.divideString(s2, k2, fill2);
    cout << "Output 2: ";
    printVector(res2);  // Output: ["abc", "def", "ghi", "jxx"]

    return 0;
}
