/*You are given a 2D array points[][], where each element represents a point (xi , yi) in a 2D plane. Your task is to find all the points that form the convex hull — the smallest convex polygon that encloses all the given points. If the given points are insufficient or do not form a valid convex polygon, return -1.

Note: Convex hull is the smallest convex polygon that contains a given set of points. It is the minimal boundary that encloses all the points such that every line segment connecting any two points within the hull lies entirely inside or on the boundary of the polygon.

You can return the points in any order, the driver code will print them in sorted order only.

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        // Cross product (p->q) x (p->r)
        int val = (q[1] - p[1]) * (r[0] - q[0]) -
                  (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;           // collinear
        return (val > 0) ? 1 : 2;         // 1 = clockwise, 2 = counterclockwise
    }

    static vector<vector<int>> findConvexHull(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return { {-1} };

        // Sort points lexicographically (first x, then y)
        sort(points.begin(), points.end());

        vector<vector<int>> lower, upper;

        // Lower hull
        for (int i = 0; i < n; ++i) {
            while (lower.size() >= 2 &&
                   orientation(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) != 2)
                lower.pop_back();
            lower.push_back(points[i]);
        }

        // Upper hull
        for (int i = n - 1; i >= 0; --i) {
            while (upper.size() >= 2 &&
                   orientation(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) != 2)
                upper.pop_back();
            upper.push_back(points[i]);
        }

        // Remove last point of upper and lower hulls (they are duplicates)
        lower.pop_back();
        upper.pop_back();

        // Concatenate lower and upper to get full hull
        vector<vector<int>> hull = lower;
        hull.insert(hull.end(), upper.begin(), upper.end());

        // Remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};

// Helper to print a 2D vector
void printPoints(vector<vector<int>>& points) {
    sort(points.begin(), points.end()); // Required as per problem statement
    for (auto& point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> points1 = {{0, 0}, {1, -4}, {-1, -5}, {-5, -3}, {-3, -1},
                                  {-1, -3}, {-2, -2}, {-1, -1}, {-2, -1}, {-1, 1}};
    vector<vector<int>> points2 = {{-2, 1}, {4, 4}, {1, -2}, {1, 1}, {2, 1}};

    Solution sol;
    
    auto hull1 = sol.findConvexHull(points1);
    cout << "Convex Hull 1: ";
    printPoints(hull1);

    auto hull2 = sol.findConvexHull(points2);
    cout << "Convex Hull 2: ";
    printPoints(hull2);

    return 0;
}
