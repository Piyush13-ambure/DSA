//
//  You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.For example:If arr[i] = 3, you can jump 1 step, 2 steps, or 3 steps forward from position i.If arr[i] = 0, you cannot jump forward from that position.Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position
//
//  Created by piyush ambure on 09/01/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class JumpGame {
public:
    // Method to calculate the minimum number of jumps to reach the end of the array
    int minJumps(const vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 1 or fewer elements, no jumps are needed
        if (n <= 1) return 0;
        
        // If the first element is 0, we cannot move forward
        if (arr[0] == 0) return -1;
        
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i < n; i++) {
            // Update the farthest point we can reach from index i
            farthest = max(farthest, i + arr[i]);
            
            // If we have reached the end of the current jump range
            if (i == currentEnd) {
                jumps++;  // We made a jump
                currentEnd = farthest;
                
                // If we can reach or exceed the last index, return the result
                if (currentEnd >= n - 1) {
                    return jumps;
                }
            }
        }
        
        return -1;  // If it's impossible to reach the end
    }
};

int main() {
    // Test case
    vector<int> arr = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    
    // Create an instance of JumpGame class
    JumpGame jumpGame;
    
    // Call the minJumps method on the class instance
    int result = jumpGame.minJumps(arr);
    
    // Output the result
    if (result == -1) {
        cout << "Not possible to reach the end!" << endl;
    } else {
        cout << "Minimum number of jumps: " << result << endl;
    }

    return 0;
}

