//Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

//The distance between two points on the X-Y plane is the Euclidean distance, defined as: 

//sqrt( (x2 - x1)2 + (y2 - y1)2 )

//You can return the k closest points in any order. The answer is guaranteed to be unique



#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create a max-heap (priority queue) with a custom comparator
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int x = point[0], y = point[1];
            int distSquared = x * x + y * y; // Calculate squared distance
            maxHeap.push({distSquared, point}); // Push distance and point

            // If the heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract k closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> result = sol.kClosest(points, k);
    cout << "The " << k << " closest points to the origin are:" << endl;
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
