/*Design a search query autocomplete system for a search engine.

The users will input a sentence ( which may have multiple words and ends with special character '#').

For each character they type except '#', you need to return the top 3 previously entered and most frequently queried sentences that have prefix the same as the part of sentence already typed.

Here are the specific rules:

The frequency for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 sentences should be sorted by frequency (The first is the most frequent).  If several sentences have the same frequency, you need to use ASCII-code order (smaller one appears first).
If less than 3 valid sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
 

Your job is to implement the methods of the AutoCompleteSystem:

AutoCompleteSystem(String[] sentences, int[] times): This is the constructor. The input is previously used data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical sentences.
Now, the user wants to input a new sentence. The following function will provide the next character the user types:

String[] input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output an array will be the top 3 historical sentences that have prefix the same as the part of sentence already typed.*/


#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<string, int> freqMap;  // Stores sentence frequency
    TrieNode* children[27] = {}; // 26 lowercase letters + ' ' (space)
};

class AutoCompleteSystem {
private:
    TrieNode* root;
    TrieNode* currNode;
    string currInput;
    
    int getIndex(char c) {
        return (c == ' ') ? 26 : (c - 'a');
    }

    void insert(string sentence, int freq) {
        TrieNode* node = root;
        for (char c : sentence) {
            int idx = getIndex(c);
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->freqMap[sentence] += freq; // Update frequency in each node
        }
    }

    vector<string> search(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = getIndex(c);
            if (!node->children[idx])
                return {};  // No sentences found
            node = node->children[idx];
        }

        // Min heap to store top 3 results (sort by freq and ASCII order)
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return (a.first == b.first) ? a.second > b.second : a.first < b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto& [sentence, freq] : node->freqMap) {
            pq.push({freq, sentence});
            if (pq.size() > 3) pq.pop();  // Keep only top 3
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());  // Get highest frequency first
        return result;
    }

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        currNode = root;
        currInput = "";

        for (size_t i = 0; i < sentences.size(); ++i)
            insert(sentences[i], times[i]);
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(currInput, 1);  // Store new sentence in history
            currNode = root;
            currInput = "";
            return {};
        }

        currInput += c;
        return search(currInput);
    }
};

// Driver Code
int main() {
    vector<string> sentences = {"i love you", "island", "ironman", "i love geeksforgeeks"};
    vector<int> times = {5, 3, 2, 2};

    AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);

    // Simulating user input
    vector<char> inputs = {'i', ' ', 'a', '#', 'i', ' '};

    for (char c : inputs) {
        vector<string> suggestions = obj->input(c);
        cout << "Input: " << c << " -> Suggestions: ";
        for (const string& s : suggestions) cout << "\"" << s << "\" ";
        cout << endl;
    }

    return 0;
}

