/*You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long mid) {
        long long total_cars = 0;
        for (int rank : ranks) {
            long long max_cars = sqrt(mid / rank); // Maximum cars this mechanic can repair in 'mid' minutes
            total_cars += max_cars;
            if (total_cars >= cars) return true; // Early exit if we already reach the target
        }
        return total_cars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    Solution sol;
    cout << sol.repairCars(ranks, cars) << endl;
    return 0;
}
