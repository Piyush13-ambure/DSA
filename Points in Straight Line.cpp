/*Given two arrays X[] and Y[] of points where (Xi, Yi) represents a point on the X-Y plane. Your task is to complete the function maxPoints which returns an integer denoting the maximum number of points that lie on the same straight line.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxPoints() which takes two lists of coordinates as input and returns the maximum number of points that lies on the same line.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(int X[], int Y[], int N) {
        if (N <= 2) return N;
        int maxAns = 0;
        
        for (int i = 0; i < N; i++) {
            map<pair<int, int>, int> slopeCount;
            int samePoints = 1;
            int currMax = 0;
            
            for (int j = i + 1; j < N; j++) {
                int dx = X[j] - X[i];
                int dy = Y[j] - Y[i];
                
                if (dx == 0 && dy == 0) {
                    samePoints++;
                } else {
                    int gcd = __gcd(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                    
                    // Normalize to avoid negative-zero issues
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    slopeCount[{dx, dy}]++;
                    currMax = max(currMax, slopeCount[{dx, dy}]);
                }
            }
            maxAns = max(maxAns, currMax + samePoints);
        }
        
        return maxAns;
    }
};

// Example main function
int main() {
    Solution sol;

    int X1[] = {1, 2, 3};
    int Y1[] = {1, 2, 3};
    int N1 = 3;
    cout << sol.maxPoints(X1, Y1, N1) << endl;  // Output: 3

    int X2[] = {1, 3, 5, 4, 2, 1};
    int Y2[] = {1, 2, 3, 1, 3, 4};
    int N2 = 6;
    cout << sol.maxPoints(X2, Y2, N2) << endl;  // Output: 4

    return 0;
}
