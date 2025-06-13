/*Geek is a chemical scientist who is performing an experiment to find an antidote to a poison. The experiment involves mixing some solutions in a flask. Based on the theoretical research Geek has done, he came up with an n * 2 array 'mix', where mix[i] = {X, Y} denotes solutions X and Y that needs to be mixed.

Also, from his past experience, it has been known that mixing some solutions leads to an explosion and thereby completely ruining the experiment. The explosive solutions are also provided as a m * 2 array 'danger' where danger[i] = {P, Q} denotes that if somehow solutions P and Q get into the same flask it will result in an explosion.

Help the Geek by returning an array 'answer' of size n, where answer[i] = "Yes" if it is safe to mix solutions in 'mix[i]' or else answer[i] = "No".

Note: Geek should follow the order of mixing of solutions as it is in 'mix' otherwise the antidote will be ineffective. Also, Geek will not mix the solutions in 'mix[i]' once he gets to know that mixing them will result in an explosion. Mixing a solution will effect the other solutions which will appear after it.
Your Task:

You don't need to read input or print anything. Complete the function avoidExplosion() which takes the mix array, its size, danger array, and its size as input parameters and returns the result array or list.

*/


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; // Union
        }
    }

private:
    vector<int> parent;
};

vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
    UnionFind uf(1001); // Assuming solution numbers are within 1 to 1000
    vector<string> answer(n, "Yes");
    
    // Create a map to store dangerous pairs for quick lookup
    unordered_map<int, unordered_map<int, bool>> dangerMap;
    for (const auto& d : danger) {
        dangerMap[d[0]][d[1]] = true;
        dangerMap[d[1]][d[0]] = true; // Since danger is bidirectional
    }

    for (int i = 0; i < n; ++i) {
        int x = mix[i][0];
        int y = mix[i][1];

        // Check if mixing x and y is dangerous
        bool isDangerous = false;
        for (const auto& d : danger) {
            if ((uf.find(d[0]) == uf.find(x) && uf.find(d[1]) == uf.find(y)) ||
                (uf.find(d[0]) == uf.find(y) && uf.find(d[1]) == uf.find(x))) {
                isDangerous = true;
                break;
            }
        }

        if (isDangerous) {
            answer[i] = "No";
        } else {
            answer[i] = "Yes";
            uf.unionSets(x, y); // Union the two solutions
        }
    }

    return answer;
}

// Main function for testing
int main() {
    int n = 5, m = 2;
    vector<vector<int>> mix = {{1, 2}, {2, 3}, {4, 5}, {3, 5}, {2, 4}};
    vector<vector<int>> danger = {{1, 3}, {4, 2}};
    
    vector<string> result = avoidExplosion(mix, n, danger, m);
    
    for (const string& res : result) {
        cout << res << " ";
    }
    return 0;
}
