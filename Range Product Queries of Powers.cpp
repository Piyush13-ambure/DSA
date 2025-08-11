/*Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

*/

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long> p2;
        vector<int> res;
        int mod = 1e9+7, i = 0;
        while (n) {
            if (n & 1) {
                p2.push_back(1L << i); // store actual power
            }
            n >>= 1;
            i++;
        }
        for (auto &q : queries) {
            long long prod = 1;
            for (int j = q[0]; j <= q[1]; j++) {
                prod = (prod * p2[j]) % mod;
            }
            res.push_back(prod);
        }
        return res;
    }
};
