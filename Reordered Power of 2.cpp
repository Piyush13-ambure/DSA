/*You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
};
