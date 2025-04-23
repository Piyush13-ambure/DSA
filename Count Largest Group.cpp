/*You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;

        // Step 1 & 2: Group numbers by digit sum
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            groupCount[sum]++;
        }

        // Step 3: Find the maximum group size
        int maxSize = 0;
        for (auto& pair : groupCount) {
            if (pair.second > maxSize) {
                maxSize = pair.second;
            }
        }

        // Step 4: Count how many groups have maxSize
        int result = 0;
        for (auto& pair : groupCount) {
            if (pair.second == maxSize) {
                result++;
            }
        }

        return result;
    }

private:
    // Helper function to calculate digit sum
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

// Example main function
int main() {
    Solution sol;
    cout << "Output for n = 13: " << sol.countLargestGroup(13) << endl; // Output: 4
    cout << "Output for n = 2: " << sol.countLargestGroup(2) << endl;   // Output: 2
    return 0;
}
