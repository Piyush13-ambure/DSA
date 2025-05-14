/*You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Initialize the transition matrix
        vector<vector<long long>> trans(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i)
            trans[i][i] = nums[i];  // Each character grows into nums[i] characters of varying types, but only length matters

        // Matrix exponentiation: trans^t
        vector<vector<long long>> powered = matrixExpo(trans, t);

        // Multiply initial frequency with powered matrix
        vector<long long> result(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                result[i] = (result[i] + freq[j] * powered[j][i]) % MOD;

        long long total = 0;
        for (int i = 0; i < 26; ++i)
            total = (total + result[i]) % MOD;

        return total;
    }

private:
    vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
        return res;
    }

    vector<vector<long long>> matrixExpo(vector<vector<long long>> base, int power) {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        // Identity matrix
        for (int i = 0; i < n; ++i)
            result[i][i] = 1;

        while (power > 0) {
            if (power % 2)
                result = matrixMultiply(result, base);
            base = matrixMultiply(base, base);
            power /= 2;
        }
        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "abcyy";
    int t1 = 2;
    vector<int> nums1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    cout << "Output 1: " << sol.lengthAfterTransformations(s1, t1, nums1) << endl;  // Expected: 7

    string s2 = "azbk";
    int t2 = 1;
    vector<int> nums2(26, 2); // All elements = 2
    cout << "Output 2: " << sol.lengthAfterTransformations(s2, t2, nums2) << endl;  // Expected: 8

    return 0;
}
