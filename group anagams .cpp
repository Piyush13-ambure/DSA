//Given an array of strings strs, group the anagrams together. You can return the answer in any order.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each word
        for (string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end()); // Sort the word
            anagramGroups[sortedWord].push_back(word);  // Store in hash map
        }

        // Collect all grouped anagrams
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};

// Main function to test the implementation
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    
    vector<string> strs(n);
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) cin >> strs[i];

    Solution obj;
    vector<vector<string>> groupedAnagrams = obj.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : groupedAnagrams) {
        cout << "[ ";
        for (const auto& word : group) cout << word << " ";
        cout << "]\n";
    }

    return 0;
}


