/*You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count.*/

// this version is slight modified for LC 3027
class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    static int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=P[i][1];
            for(int j = i+1; j<n; j++){
                const int yj=P[j][1];
                if (yj>=yi && y>yj){//P[j] cannot be in between
                    ans++;
                    y=yj;
                }
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
