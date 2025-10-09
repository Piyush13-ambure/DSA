/*In a town plagued by thieves, the mayor has a list of n thieves that are scheduled to be caught, numbered 1 through n. Each thief:

Has a threat level ai (positive integer), and
Belongs to a specific gang type b? (an integer between 1 and m inclusive).
To aid in the operation, the mayor can assign up to m special guards, one per gang. The guard of gang type j can neutralize all threats from that gang's thieves.
The mayor begins the operation with a total preparedness level h (his ability to endure threats without failing the mission). The plan is carried out in order from thief 1 to thief n, following these steps:
For each thief i = 1 to n, as long as preparedness is positive:
If no guard is assigned for the gang b?:

The thief deals a? threat to the mayor (subtract a? from h).
If after that, h > 0:

The thief is captured.
Otherwise:

The mayor fails, and no more thieves can be dealt with.
You are to solve the following task for every possible number of guards k= 0, 1, …, m:
Determine the maximum number of thieves that the mayor can successfully capture when he assigns exactly k guards (choosing them from the available m gang types)*/
class Solution {
  public:
    vector<int> solve(int n, int m, int h, vector<int>& a, vector<int>& b) {
        vector<int> grp(m, 0);
        multiset<int> used, unused;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            b[i] = b[i] - 1;
        }
        for (int i = 0; i < m; i++)
            unused.insert(grp[i]);

        int k = 0;
        vector<int> res(m + 1);

        for (int i = 0; i < n; i++) {
            int g = b[i];
            if (used.find(grp[g]) != used.end()) {
                used.erase(used.find(grp[g]));
            } else {
                unused.erase(unused.find(grp[g]));
                cur -= grp[g];
            }

            grp[g] += a[i];
            unused.insert(grp[g]);
            cur += grp[g];

            while (used.size() < k) {
                int big = *--unused.end();
                unused.erase(unused.find(big));
                cur -= big;
                used.insert(big);
            }

            while (!used.empty() && !unused.empty()) {
                int sml = *used.begin();
                int big = *--unused.end();

                if (big > sml) {
                    unused.erase(unused.find(big));
                    unused.insert(sml);
                    cur -= big;
                    cur += sml;
                    used.erase(used.find(sml));
                    used.insert(big);
                } else
                    break;
            }

            while (cur >= h) {
                res[k] = i;
                k++;

                int big = *--unused.end();
                unused.erase(unused.find(big));
                cur -= big;
                used.insert(big);
            }
        }

        while (k <= m)
            res[k++] = n;

        return res;
    }
};
