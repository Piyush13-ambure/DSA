/*For a given non-negative integer N, find the next smallest Happy Number. A number is called Happy if it leads to 1 after a sequence of steps. Wherein at each step the number is replaced by the sum of squares of its digits that is, if we start with Happy Number and keep replacing it with sum of squares of its digits, we reach 1 at some point.
Your Task:
You don't need to read input or print anything. Your task is to complete the function nextHappy() which takes an integer N as input parameters and returns an integer, next Happy number after N.
 */


#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to determine if a number is Happy
    bool isHappy(int num) {
        unordered_set<int> seen;
        while (num != 1 && seen.find(num) == seen.end()) {
            seen.insert(num);
            num = sumOfSquares(num);
        }
        return num == 1;
    }

    // Helper function to calculate sum of squares of digits
    int sumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }

    // Function to find the next happy number after N
    int nextHappy(int N) {
        int next = N + 1;
        while (!isHappy(next)) {
            next++;
        }
        return next;
    }
};

// Main function for testing
int main() {
    Solution sol;
    int N;
    cout << "Enter a number: ";
    cin >> N;
    cout << "Next Happy Number after " << N << " is " << sol.nextHappy(N) << endl;
    return 0;
}

