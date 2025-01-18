//Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.
//Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> dict, int k) {
        // Step 1: Create a graph
        vector<vector<int>> graph(k);
        vector<int> indegree(k, 0);

        // Step 2: Build the graph based on the dictionary
        for (int i = 0; i < dict.size() - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.size(), word2.size());
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    graph[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break; // Only the first differing character matters
                }
            }
        }

        // Step 3: Topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        string order;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            order += (current + 'a');

            for (int neighbor : graph[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the order contains all characters, return it; otherwise, return an empty string
        return (order.size() == k) ? order : "";
    }
};

// Main function to test the Solution class
int main() {
    int n, k;
    cout << "Enter the number of words in the dictionary: ";
    cin >> n;
    cout << "Enter the number of starting alphabets (k): ";
    cin >> k;

    vector<string> dict(n);
    cout << "Enter the words in the dictionary:\n";
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }

    Solution solution;
    string result = solution.findOrder(dict, k);

    if (!result.empty()) {
        cout << "The order of characters in the alien language is: " << result << endl;
    } else {
        cout << "No valid ordering of letters is possible." << endl;
    }

    return 0;
}
