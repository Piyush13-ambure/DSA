//Given an integer x, return true if x is a palindrome, and false otherwise.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending in 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // The number is a palindrome if it is equal to its reversed half
        // For odd-length numbers, reversedHalf/10 removes the middle digit
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Test cases
    int testCases[] = {121, -121, 10, 0, 1221, 12321, 1001};
    
    for (int x : testCases) {
        cout << "Is " << x << " a palindrome? " 
             << (solution.isPalindrome(x) ? "True" : "False") << endl;
    }

    return 0;
}
