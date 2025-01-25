//Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
//A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

//For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }

    bool isStronglyConnected(vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &outDegree) {
        int n = 26; // Total number of letters (a-z)
        vector<bool> visited(n, false);

        // Find the first vertex with a non-zero degree
        int startNode = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0 || outDegree[i] > 0) {
                startNode = i;
                break;
            }
        }

        // Perform DFS starting from the first vertex with a non-zero degree
        if (startNode == -1) return true; // No edges, considered a valid circle
        dfs(startNode, visited, adj);

        // Check if all vertices with non-zero degree are visited
        for (int i = 0; i < n; i++) {
            if ((inDegree[i] > 0 || outDegree[i] > 0) && !visited[i]) {
                return false;
            }
        }

        return true;
    }

    int isCircle(vector<string> &arr) {
        int n = arr.size();
        vector<int> inDegree(26, 0), outDegree(26, 0);
        vector<vector<int>> adj(26);

        // Build the graph
        for (string &s : arr) {
            int first = s[0] - 'a';
            int last = s.back() - 'a';
            outDegree[first]++;
            inDegree[last]++;
            adj[first].push_back(last);
        }

        // Check if in-degree and out-degree of every vertex are equal
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) {
                return 0; // Not a valid circle
            }
        }

        // Check if the graph is strongly connected
        return isStronglyConnected(adj, inDegree, outDegree) ? 1 : 0;
    }
};

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.isCircle(arr);

    if (result == 1) {
        cout << "Yes, the strings can form a circle." << endl;
    } else {
        cout << "No, the strings cannot form a circle." << endl;
    }

    return 0;
}
