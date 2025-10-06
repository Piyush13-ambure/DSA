/*You are given two integer arrays a[] and b[]. Return all the starting indexes of all the occurences of b[] as a subarray in a[].*/
class Solution {
  public:
    void constructLps(vector<int> &b, vector<int> &lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;

        while (i < b.size()) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        vector<int> lps(m);
        vector<int> res;

        constructLps(b, lps);

        int i = 0; // Index for a[]
        int j = 0; // Index for b[]

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;

                if (j == m) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};
