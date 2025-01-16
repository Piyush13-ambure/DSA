//
//  main.cpp
//  minimum pateformes
//
//  Created by piyush ambure on 16/01/25.
//

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Sort both the arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms_needed = 0, max_platforms = 0;
        int i = 0, j = 0;

        // Use two pointers to traverse arrival and departure arrays
        while (i < n && j < n) {
            // If a train arrives before or when the previous one departs
            if (arr[i] <= dep[j]) {
                platforms_needed++; // A new platform is needed
                i++;
            } else {
                // If a train departs, reduce the count of platforms needed
                platforms_needed--;
                j++;
            }
            // Update the maximum platforms needed
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};
