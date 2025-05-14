/*There are two parallel roads, each containing n and m buckets, respectively. Each bucket may contain some balls. The balls in the first road are given in an array a of size n and balls in the second road in an array b of size m. The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the left side of the road. Geek can change the road only at a point of intersection i.e. a point where buckets have the same number of balls on two roads. Help Geek collect the maximum number of balls.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxBalls() which takes n, m, a[] and b[] as input parameters and returns the maximum number of balls that can be collected.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxBalls(int n, int m, vector<int> a, vector<int> b) {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (a[i] > b[j]) {
                sum2 += b[j++];
            } else {
                // Intersection point
                sum1 += a[i++];
                sum2 += b[j++];
                result += max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
            }
        }

        // Add remaining balls from either road
        while (i < n) sum1 += a[i++];
        while (j < m) sum2 += b[j++];

        result += max(sum1, sum2);
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 5, m1 = 5;
    vector<int> a1 = {1, 4, 5, 6, 8};
    vector<int> b1 = {2, 3, 4, 6, 9};
    cout << "Example 1 Output: " << sol.maxBalls(n1, m1, a1, b1) << endl;  // Output: 29

    // Example 2
    int n2 = 3, m2 = 3;
    vector<int> a2 = {1, 2, 3};
    vector<int> b2 = {4, 5, 6};
    cout << "Example 2 Output: " << sol.maxBalls(n2, m2, a2, b2) << endl;  // Output: 15

    return 0;
}

