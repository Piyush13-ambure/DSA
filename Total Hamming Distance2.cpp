//Given an integer array arr[], return the sum of Hamming distances between all the pairs of the integers in arr.

//Note: The answer is guaranteed to fit within a 32-bit integer.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totHammingDist(vector<int>& arr) {
        int total = 0;
        int n = arr.size();

        // Iterate through each bit position (0 to 29, since max value is 10^9)
        for (int bit = 0; bit < 30; bit++) {
            int count1 = 0;  // Count of numbers with this bit set
            for (int num : arr) {
                if (num & (1 << bit)) count1++;
            }
            int count0 = n - count1;
            total += count1 * count0; // Each 1 pairs with a 0
        }

        return total;
    }
};

int main() {
    vector<int> arr = {4, 14, 4, 14}; // Example input
    Solution sol;
    cout << "Total Hamming Distance: " << sol.totHammingDist(arr) << endl;
    return 0;
}
