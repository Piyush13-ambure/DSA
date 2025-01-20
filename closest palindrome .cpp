//iven a number num, our task is to find the closest Palindrome number whose absolute difference with the given number is minimal. If 2 Palindrome numbers have the same absolute difference as the given number, take the smaller one.
 #include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to convert a string to long long
    long long int stringToLong(string s) {
        long long int num = 0;
        for (char c : s) {
            num = num * 10 + (c - '0');
        }
        return num;
    }
    
    // Function to generate a palindrome by reflecting the first half
    long long int generatePalindrome(long long int num) {
        string str = to_string(num);
        int len = str.size();
        string firstHalf = str.substr(0, (len + 1) / 2);  // First half (includes middle if odd length)
        string palindrome = firstHalf;
        
        // If the length of the number is odd, remove the last character before reflecting
        if (len % 2 != 0) {
            firstHalf = firstHalf.substr(0, firstHalf.size() - 1);
        }
        
        // Create a palindrome by reflecting the first half
        palindrome += string(firstHalf.rbegin(), firstHalf.rend());
        return stringToLong(palindrome);
    }
    
    // Function to find closest palindrome
    long long int closestPalindrome(long long int num) {
        if (num == 0) return 1;
        
        string strNum = to_string(num);
        int len = strNum.size();
        
        // Generate the closest palindrome by reflecting the first half
        long long int closest = generatePalindrome(num);
        
        // Check the adjacent palindromes by adjusting the first half
        long long int higherHalf = num + 1;
        long long int lowerHalf = num - 1;
        
        long long int higherPalindrome = generatePalindrome(higherHalf);
        long long int lowerPalindrome = generatePalindrome(lowerHalf);
        
        // Now compare the candidates: num, higherPalindrome, lowerPalindrome
        long long int result = closest;
        
        if (abs(higherPalindrome - num) < abs(result - num) || 
            (abs(higherPalindrome - num) == abs(result - num) && higherPalindrome < result)) {
            result = higherPalindrome;
        }
        
        if (abs(lowerPalindrome - num) < abs(result - num) || 
            (abs(lowerPalindrome - num) == abs(result - num) && lowerPalindrome < result)) {
            result = lowerPalindrome;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    long long int num = 12345;
    cout << "Closest palindrome to " << num << " is: " << solution.closestPalindrome(num) << endl;
    
    num = 999;
    cout << "Closest palindrome to " << num << " is: " << solution.closestPalindrome(num) << endl;
    
    num = 1001;
    cout << "Closest palindrome to " << num << " is: " << solution.closestPalindrome(num) << endl;
    
    return 0;
}
