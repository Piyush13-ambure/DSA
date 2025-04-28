/*Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".*/


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Store all contacts in a set to maintain uniqueness and sorted order
        set<string> contactSet(contact, contact + n);
        vector<string> contactList(contactSet.begin(), contactSet.end());

        vector<vector<string>> result;

        string prefix = "";
        for (char ch : s) {
            prefix += ch;
            vector<string> matchedContacts;
            
            for (auto &c : contactList) {
                if (c.substr(0, prefix.size()) == prefix) {
                    matchedContacts.push_back(c);
                }
            }
            
            if (matchedContacts.empty()) {
                matchedContacts.push_back("0");
            }
            result.push_back(matchedContacts);
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n; // number of contacts
        string contact[n];
        for (int i = 0; i < n; ++i) {
            cin >> contact[i];
        }
        string s;
        cin >> s; // query string
        
        Solution obj;
        vector<vector<string>> ans = obj.displayContacts(n, contact, s);
        
        for (auto &prefixList : ans) {
            for (auto &name : prefixList) {
                cout << name << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
