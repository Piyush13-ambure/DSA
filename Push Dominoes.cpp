/*There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.*/



class Solution {
public:
    static string pushDominoes(string& s) {
        const int n = s.size();
        char* const ch = s.data();
        char p = '.';
        int j = 0;
        for (int i = 0; i < n; ++i) {
            const char ai = s[i];
            if (ai == 'R') {
                if (p == 'R') fill(ch + j, ch + i, 'R');
                p = 'R';
                j = i;
            } else if (ai == 'L') {
                if (p == '.') {
                    fill(ch + j, ch + i + 1, 'L');
                } else {
                    const int h = (i - j + 1) >> 1;
                    fill(ch + j, ch + j + h, 'R');
                    fill(ch + i - h + 1, ch + i + 1, 'L');
                }
                j = i + 1;
                p = '.';
            }
        }
        if (p == 'R') fill(ch + j, ch + n, 'R');
        return s;
    }
};
