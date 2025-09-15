/*There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

*/


class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) broken[c - 'a'] = true;

        int count = 0;
        bool ok = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i < text.size() && text[i] != ' ') {
                if (broken[text[i] - 'a']) ok = false;
            } else {
                if (ok) count++;
                ok = true;
            }
        }
        return count;
    }
};
