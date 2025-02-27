//Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
//A reversal means changing '{' to '}' or vice-versa.



#include <bits/stdc++.h>
using namespace std;

int countRev(string s) {
    int n = s.length();
    
    // If length is odd, balancing is impossible
    if (n % 2 != 0) return -1;
    
    int open = 0, close = 0;
    
    for (char c : s) {
        if (c == '{') {
            open++;
        } else { // c == '}'
            if (open > 0) {
                open--; // Matched a pair
            } else {
                close++; // Unmatched closing bracket
            }
        }
    }
    
    // Minimum reversals needed
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
    return 0;
}
