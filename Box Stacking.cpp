/*You are given a set of some types of rectangular 3-D boxes, where the ith box has height, width, and length height[i], width[i], and length[i] respectively. You have to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box. Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Note: Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.*/

#include <bits/stdc++.h>
using namespace std;

class Box {
public:
    int h, w, l;
    Box(int height, int width, int length) {
        h = height;
        w = min(width, length);
        l = max(width, length);
    }
};

bool compare(Box a, Box b) {
    return a.l * a.w > b.l * b.w;
}

class Solution {
public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();
        vector<Box> boxes;

        // Generate all 3 rotations for each box
        for (int i = 0; i < n; i++) {
            boxes.push_back(Box(height[i], width[i], length[i]));
            boxes.push_back(Box(width[i], height[i], length[i]));
            boxes.push_back(Box(length[i], width[i], height[i]));
        }

        // Sort the boxes based on base area (l * w) in descending order
        sort(boxes.begin(), boxes.end(), compare);

        int m = boxes.size();
        vector<int> dp(m);

        // Initialize dp[i] with height of i-th box
        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i].h;
        }

        // Compute optimized dp[i]
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[i].l < boxes[j].l && boxes[i].w < boxes[j].w) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }
        }

        // Find maximum in dp[]
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> height1 = {4, 1, 4, 10};
    vector<int> width1 = {6, 2, 5, 12};
    vector<int> length1 = {7, 3, 6, 32};
    cout << "Max height: " << sol.maxHeight(height1, width1, length1) << endl;  // Output: 60

    // Example 2
    vector<int> height2 = {1, 4, 3};
    vector<int> width2 = {2, 5, 4};
    vector<int> length2 = {3, 6, 1};
    cout << "Max height: " << sol.maxHeight(height2, width2, length2) << endl;  // Output: 15

    // Example 3
    vector<int> height3 = {3};
    vector<int> width3 = {2};
    vector<int> length3 = {6};
    cout << "Max height: " << sol.maxHeight(height3, width3, length3) << endl;  // Output: 3

    return 0;
}
