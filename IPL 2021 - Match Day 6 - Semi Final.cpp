/*IPL 2021 knockouts are over, teams MI, CSK, DC, and RCB are qualified for the semis.

Today is matchday 6 and it is between Delhi Capitals and Royal Challengers Banglore. Glenn Maxwell of RCB playing flawlessly. Rishabh Pant, the new captain of the team who is also a wicket-keeper wants to send a message to the bowler. But, he can't shout message directly as a batsman can hear. So, he decided to encrypt the message by putting '*'s in the message. And this is how the bowler decrypts the message. Bowler iterates over the message string from left to right, if he finds a '*', he removes it and adds all the letters read so far to the message. He keeps on doing this till he gets rid of all the '*'. Given a decrypted message in the form of the string, the task is to find the encrypted message.

Note: If the string can be encrypted in multiple ways, find the encrypted string of smallest length.*/


#include <iostream>
using namespace std;

class Solution {
public:
    string compress(string s) {
        int n = s.size();
        string result = "";
        int i = 0;
        
        while (i < n) {
            int j = (i > 0) ? (i + 1) / 2 : 1;
            while (j < i + 1 && s.substr(0, j) != s.substr(i + 1 - j, j)) {
                j++;
            }
            if (j < i + 1) {
                result += "*";
                i += j - 1;
            } else {
                result += s[i];
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Compressed String: " << sol.compress(s) << endl;
    return 0;
}
