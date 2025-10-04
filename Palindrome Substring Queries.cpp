/*Given a string s and a 2D list queries[][] of size q, where each queries[i] consists of two integers [left, right]. Each query refers to the substring s[left : right], where both left and right are inclusive (0-based indexing).

For each query, find whether the substring s[left : right] forms a palindrome.*/

class RollingHash {
  public:
    const int mod = 1e9 + 7;
    const int base1 = 4441;
    const int base2 = 7817;

    int length;
    string input;
    vector<vector<int>> preHash;
    vector<vector<int>> power;

    RollingHash(string& str) {
        input = str;
        length = input.size();
        preHash.assign(length + 1, vector<int>(2, 0));
        power.assign(length + 1, vector<int>(2, 1));
        buildHashes();
    }

    int add(int a, int b) { return (a + b) % mod; }

    int subtract(int a, int b) { return (a - b + mod) % mod; }

    int multiply(int a, int b) { return (1LL * a * b) % mod; }

    void buildHashes() {
        for (int i = 0; i < length; i++) {
            preHash[i + 1][0] = add(multiply(preHash[i][0], base1), input[i]);
            preHash[i + 1][1] = add(multiply(preHash[i][1], base2), input[i]);

            power[i + 1][0] = multiply(power[i][0], base1);
            power[i + 1][1] = multiply(power[i][1], base2);
        }
    }

    // get hash of input[left...right-1]
    vector<int> getHash(int left, int right) {
        vector<int> result(2);
        for (int b = 0; b < 2; ++b) {
            result[b] = subtract(preHash[right][b],
                                 multiply(preHash[left][b], power[right - left][b]));
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> palQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        string revS = s;
        reverse(revS.begin(), revS.end());

        RollingHash forwardHash(s);
        RollingHash reverseHash(revS);
        vector<int> result;

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];

            // get hash of s[left...right]
            vector<int> h1 = forwardHash.getHash(left, right + 1);

            // map to reversed string: revS[n-1-right ... n-1-left]
            int revLeft = n - 1 - right;
            int revRight = n - left;
            vector<int> h2 = reverseHash.getHash(revLeft, revRight);

            if (h1 == h2) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};
