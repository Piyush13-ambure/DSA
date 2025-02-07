//Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and the count of set bit in X is equal to the count of set bits in B.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minVal(int A, int B) {
        int setBitsB = __builtin_popcount(B);  // Count set bits in B
        int setBitsA = __builtin_popcount(A);  // Count set bits in A
        int result = A;

        if (setBitsA > setBitsB) {
            // Remove extra set bits (rightmost ones first)
            for (int i = 0; i < 32 && setBitsA > setBitsB; i++) {
                if (result & (1 << i)) {
                    result ^= (1 << i);  // Turn off the bit
                    setBitsA--;
                }
            }
        } else if (setBitsA < setBitsB) {
            // Add extra set bits (leftmost zeros first)
            for (int i = 0; i < 32 && setBitsA < setBitsB; i++) {
                if (!(result & (1 << i))) {
                    result |= (1 << i);  // Turn on the bit
                    setBitsA++;
                }
            }
        }
        return result;
    }
};

// Main function to test the solution
int main() {
    Solution obj;
    
    // Example 1
    int A1 = 3, B1 = 5;
    cout << obj.minVal(A1, B1) << endl;  // Output: 3
    
    // Example 2
    int A2 = 7, B2 = 12;
    cout << obj.minVal(A2, B2) << endl;  // Output: 6
    
    return 0;
}
