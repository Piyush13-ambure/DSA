/*Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt can only be compared with the nut to see which one is bigger/smaller.
The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        vector<char> order = { '!', '#', '$', '%', '&', '*', '?', '@', '^' };

        // Create a hash map to track the presence of characters
        unordered_set<char> nutsSet(nuts, nuts + n);
        unordered_set<char> boltsSet(bolts, bolts + n);

        // Sorting both arrays based on the predefined order
        int index = 0;
        for (char ch : order) {
            if (nutsSet.count(ch) && boltsSet.count(ch)) {
                nuts[index] = ch;
                bolts[index] = ch;
                index++;
            }
        }
    }
};

// Main function to test the program
int main() {
    int n = 5;
    char nuts[] = { '@', '%', '$', '#', '^' };
    char bolts[] = { '%', '@', '#', '$', '^' };

    Solution obj;
    obj.matchPairs(n, nuts, bolts);

    // Printing sorted nuts and bolts
    for (int i = 0; i < n; i++) cout << nuts[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << bolts[i] << " ";
    cout << endl;

    return 0;
}
