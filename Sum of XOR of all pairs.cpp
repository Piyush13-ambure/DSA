/*Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).*/


#include <iostream>
using namespace std;

class Solution {
public:
    long long int sumXOR(int arr[], int n) {
        long long int result = 0;
        
        // Iterate over each bit position (0 to 31)
        for (int i = 0; i < 32; i++) {
            long long count1 = 0, count0 = 0;
            
            // Count how many numbers have the i-th bit set
            for (int j = 0; j < n; j++) {
                if (arr[j] & (1 << i))
                    count1++;
                else
                    count0++;
            }
            
            // Contribution of this bit to the total XOR sum
            result += (count1 * count0 * (1LL << i));
        }
        
        return result;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    int arr1[] = {7, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << sol.sumXOR(arr1, n1) << endl; // Output: 12

    int arr2[] = {5, 9, 7, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << sol.sumXOR(arr2, n2) << endl; // Output: 47

    return 0;
}
