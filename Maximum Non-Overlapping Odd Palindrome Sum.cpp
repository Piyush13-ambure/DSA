/*Given a string s consisting of lowercase English letters, find the maximum possible sum of the lengths of any two non-empty and non-overlapping palindromic substrings of odd length.

Formally, choose any two substrings s[i...j] and s[k...l] such that 1 ≤ i ≤ j < k ≤ l ≤ s.size(), both substrings are palindromes of odd length, and they do not overlap. Return the maximum sum of their lengths.

Note: A palindrome is a string that reads the same forward and backward. A substring is a contiguous sequence of characters within the string.

*/

class manacher {
  public:
    vector<int> p;
    string ms;

    manacher(string &s) {
        ms = "@";

        for (char c : s) {
            ms += "#";
            ms += c;
        }

        ms += "#$";

        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);

        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i) {

            // If inside current right boundary, use previously
            // computed value by mirroring
            if (r + l - i < n && r + l - i >= 0) {
                p[i] = max(0, min(r - i, p[r + l - i]));
            }

            // Expand the palindrome centered at i
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                   ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                ++p[i];
            }

            // Update the current palindrome boundary
            // if this one extends further
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // Returns the radius of the longest palindrome
    // centered at index `cen`
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // Check if s[l...r] is a palindrome of expected type
    bool check(int l, int r) {
        int len = r - l + 1;
        int mid = (l + r) / 2;
        return len <= getLongest(mid, len % 2);
    }
};

class Solution {
  public:
    int maxSum(string &s) {
        int n = s.size();
        vector<int> leftMark(n, 1), rightMark(n, 1);
        manacher mr(s);

        // Store the max odd-length palindrome ending
        // at or before each index
        for (int i = 0; i < n; i++) {
            int val = mr.getLongest(i, 1);
            int li = i + val / 2;
            if (li < n)
                leftMark[li] = max(leftMark[li], val);
        }

        // Spread max values backwards by reducing
        // length by 2 (odd length constraint)
        for (int i = n - 2; i >= 0; i--) {
            leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2);
        }

        // Make prefix max array
        for (int i = 1; i < n; i++) {
            leftMark[i] = max(leftMark[i], leftMark[i - 1]);
        }

        // Store the max odd-length palindrome starting
        // at or after each index
        for (int i = n - 1; i >= 0; i--) {
            int val = mr.getLongest(i, 1);
            int ri = i - val / 2;
            if (ri >= 0)
                rightMark[ri] = max(rightMark[ri], val);
        }

        // Spread max values forward by reducing
        // length by 2
        for (int i = 1; i < n; i++) {
            rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2);
        }

        // Make suffix max array
        for (int i = n - 2; i >= 0; i--) {
            rightMark[i] = max(rightMark[i], rightMark[i + 1]);
        }

        // Try every cut point and compute the best
        // non-overlapping sum
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) {
            ans = max(ans, leftMark[i] + rightMark[i + 1]);
        }

        return ans;
    }
};
