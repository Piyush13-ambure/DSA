/*You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

 */

class Solution {
public:
    static array<int, 26> freq(string& s){
        array<int, 26> ans{};
        for(char c: s){
            ans[c-'a']++;
        }
        return ans;
    }
    static vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size(), l=0, r=1;
        vector<string> ans={words[0]};
        array<int, 26> f0=move(freq(words[0]));
        for( ; r<n; r++){
            string s=words[r];
            auto x=move(freq(s));
            if (f0!=x){
                ans.push_back(s);
                l=r;
                f0=x;
            }
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
