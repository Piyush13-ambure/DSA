//We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
//Note: stations is in a strictly increasing order.
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class Solution {
public:
    double minimizeMaxDistance(vector<int>& stations, int k) {
        double left = 0.0; // Minimum possible distance
        double right = stations.back() - stations[0]; // Maximum possible distance
        double result = right;

        auto canPlaceStations = [&](double d) -> bool {
            int count = 0; // Additional gas stations needed
            for (int i = 1; i < stations.size(); ++i) {
                double gap = stations[i] - stations[i - 1];
                count += static_cast<int>(ceil(gap / d)) - 1; // Stations needed to keep gaps <= d
            }
            return count <= k;
        };

        while (right - left > 1e-6) { // Binary search precision
            double mid = (left + right) / 2.0;
            if (canPlaceStations(mid)) {
                result = mid; // Update result
                right = mid; // Try to minimize further
            } else {
                left = mid; // Increase the allowable distance
            }
        }

        return round(result * 100) / 100.0; // Round to 2 decimal places
    }
};

int main() {
    vector<int> stations = {1, 2, 8, 12};
    int k = 2;

    Solution solution;
    double result = solution.minimizeMaxDistance(stations, k);
    cout << fixed << setprecision(2);
    cout << "The smallest possible maximum distance is: " << result << endl;

    return 0;
}
