//You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
//Note: Return the numbers in their order of appearing twice. So, if x and y are repeating numbers, and x's second appearance comes before the second appearance of y, then the order should be (x, y).


#include <iostream>
#include <vector>
#include <cmath>  // For abs()

using namespace std;

class Solution {
public:
    vector<int> twoRepeated(int n, int arr[]) {
        vector<int> result;
        
        for (int i = 0; i < n + 2; i++) {
            int index = abs(arr[i]);  // Get absolute value as index
            
            // If the value at that index is already negative, this number is repeating
            if (arr[index] < 0) {
                result.push_back(index);
            } else {
                arr[index] = -arr[index];  // Mark as visited
            }
            
            if (result.size() == 2) break;  // Stop early when both numbers are found
        }
        
        return result;
    }
};

// Main function to test
int main() {
    Solution sol;
    int arr[] = {1, 2, 1, 3, 4, 3};  // n = 4
    int n = 4;
    
    vector<int> result = sol.twoRepeated(n, arr);
    
    cout << "Two repeated elements: " << result[0] << ", " << result[1] << endl;
    
    return 0;
}
