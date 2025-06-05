/*You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parent;

    Solution() {
        parent.resize(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i; // Initially, each character is its own parent
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by lexicographical order
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (px < py) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.length(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (char c : baseStr) {
            result += (char)(find(c - 'a') + 'a');
        }
        return result;
    }
};

// Main function to test the class
int main() {
    Solution sol;

    string s1 = "abc";
    string s2 = "cde";
    string baseStr = "eed";

    string result = sol.smallestEquivalentString(s1, s2, baseStr);
    cout << "Smallest Equivalent String: " << result << endl;

    return 0;
}
