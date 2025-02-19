//Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        
        // Group words by sorted version
        for (string& str : arr) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(str);
        }
        
        // Extract grouped anagrams
        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    Solution sol;
    vector<vector<string>> groupedAnagrams = sol.anagrams(words);
    
    // Print the anagram groups
    for (const auto& group : groupedAnagrams) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
