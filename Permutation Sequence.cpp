/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;  // List of available numbers
        vector<int> fact(n, 1); // Factorial values
        
        // Compute factorial values
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;

        // Initialize numbers from 1 to n
        for (int i = 1; i <= n; i++)
            numbers.push_back(i);

        // Convert k to zero-based index
        k--;

        string result = "";
        for (int i = n - 1; i >= 0; i--) {
            int index = k / fact[i];  // Determine the digit's index
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index); // Remove used number
            k %= fact[i]; // Update k for the next position
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    cout << "Output: " << solution.getPermutation(3, 3) << endl; // Expected: "213"
    cout << "Output: " << solution.getPermutation(4, 9) << endl; // Expected: "2314"
    cout << "Output: " << solution.getPermutation(3, 1) << endl; // Expected: "123"

    return 0;
}
