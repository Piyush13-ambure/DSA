/*An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.

*/

class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> list;
        vector<int> count(10, 0);
        generate(0, count, list);
        sort(list.begin(), list.end());
        for (int num : list) {
            if (num > n) return num;
        }
        return -1;
    }

private:
    void generate(long num, vector<int>& count, vector<int>& list) {
        if (num > 0 && isBeautiful(count)) {
            list.push_back((int)num);
        }
        if (num > 1224444) return;

        for (int d = 1; d <= 7; ++d) {
            if (count[d] < d) {
                count[d]++;
                generate(num * 10 + d, count, list);
                count[d]--;
            }
        }
    }

    bool isBeautiful(const vector<int>& count) {
        for (int d = 1; d <= 7; ++d) {
            if (count[d] != 0 && count[d] != d)
                return false;
        }
        return true;
    }
};
