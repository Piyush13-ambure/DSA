/*Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateBinary(int n, int ones, int zeros, string current, vector<string>& result) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        // Include '1' in the sequence
        generateBinary(n, ones + 1, zeros, current + '1', result);

        // Include '0' only if ones > zeros
        if (ones > zeros) {
            generateBinary(n, ones, zeros + 1, current + '0', result);
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> result;
        generateBinary(n, 0, 0, "", result);
        return result;
    }
};

// Driver function
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    Solution obj;
    vector<string> res = obj.NBitBinary(n);
    
    for (const string& str : res) {
        cout << str << " ";
    }
    cout << endl;
    
    return 0;
}
