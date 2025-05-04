/*Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;

        for (auto& d : dominoes) {
            // Sort the domino so [a,b] and [b,a] become the same
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;

            res += count[key];  // for each existing pair, we can form a new one
            count[key]++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Example input: [[1,2],[2,1],[3,4],[5,6]]
    vector<vector<int>> dominoes = {{1,2}, {2,1}, {3,4}, {5,6}};

    int result = sol.numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}
