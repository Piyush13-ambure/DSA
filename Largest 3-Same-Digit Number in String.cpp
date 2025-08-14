/*You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.*/

class Solution {
public:
    string largestGoodInteger(string& num) {
        int count=0;
        char prev='X', maxd=' ';
        for(char c: num){
            if (c==prev) count++;
            else count=1;
            if (count==3)
                maxd=max(maxd, c);
            prev=c;
        }
        return (maxd==' ')?"":string(3, maxd);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
