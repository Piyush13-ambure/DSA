/*Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a number can be partitioned into substrings summing up to target
    bool isValidPartition(string num, int index, int target) {
        if (index == num.size()) return target == 0;  // Base case: all digits processed
        int sum = 0;
        for (int i = index; i < num.size(); ++i) {
            sum = sum * 10 + (num[i] - '0');  // Form the substring
            if (sum > target) break;  // If sum exceeds target, stop further processing
            if (isValidPartition(num, i + 1, target - sum)) return true;  // Check next partition
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentSum = 0;

        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (isValidPartition(squareStr, 0, i)) {
                punishmentSum += square;  // Add valid punishment number
            }
        }

        return punishmentSum;
    }
};

// Main function for testing
int main() {
    Solution obj;
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Punishment Number: " << obj.punishmentNumber(n) << endl;
    
    return 0;
}
