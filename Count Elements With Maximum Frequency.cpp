/*You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

*/


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        uint8_t freq[101] = {0};
        uint8_t max = 0, res = 0;
        for (int n : nums) {
            uint8_t f = ++freq[n];
            if (f > max) {
                max = f;
                res = f;
            } else if (f == max)
                res += f;
        }
        return res;
    }
};
