//Given an integer array arr[], return the sum of Hamming distances between all the pairs of the integers in arr.

//Note: The answer is guaranteed to fit within a 32-bit integer.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totHammingDist(vector<int>& arr) {
        int totalDistance = 0;
        int n = arr.size();
        
        // Iterate over all 32 bits
        for (int bit = 0; bit < 32; ++bit) {
            int countOnes = 0;
            for (int num : arr) {
                if (num & (1 << bit)) {
                    countOnes++;
                }
            }
            int countZeros = n - countOnes;
            totalDistance += countOnes * countZeros;
        }
        
        return totalDistance;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 14, 2}; // Example input
    cout << "Total Hamming Distance: " << sol.totHammingDist(arr) << endl;
    return 0;
}
