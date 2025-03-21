/*You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // Initialize the graph and indegree count
        for (int i = 0; i < recipes.size(); i++) {
            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        vector<string> result;

        // Push recipes that have all ingredients available (indegree == 0)
        for (string& recipe : recipes) {
            if (indegree[recipe] == 0) {
                q.push(recipe);
            }
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // If we have all ingredients, we can make the recipe
            if (available.count(curr) || indegree[curr] == 0) {
                result.push_back(curr);
                available.insert(curr);  // This recipe becomes available for others
            }

            // Reduce indegree for dependent recipes
            for (string& nextRecipe : graph[curr]) {
                if (--indegree[nextRecipe] == 0) {
                    q.push(nextRecipe);
                }
            }
        }

        return result;
    }
};

// Driver Code
int main() {
    Solution obj;
    vector<string> recipes1 = {"bread"};
    vector<vector<string>> ingredients1 = {{"yeast","flour"}};
    vector<string> supplies1 = {"yeast","flour","corn"};
    vector<string> result1 = obj.findAllRecipes(recipes1, ingredients1, supplies1);
    for (string& s : result1) cout << s << " ";
    cout << endl; // Output: "bread"

    vector<string> recipes2 = {"bread","sandwich"};
    vector<vector<string>> ingredients2 = {{"yeast","flour"}, {"bread","meat"}};
    vector<string> supplies2 = {"yeast","flour","meat"};
    vector<string> result2 = obj.findAllRecipes(recipes2, ingredients2, supplies2);
    for (string& s : result2) cout << s << " ";
    cout << endl; // Output: "bread sandwich"

    return 0;
}
