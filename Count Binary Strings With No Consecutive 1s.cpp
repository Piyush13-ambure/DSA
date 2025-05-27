/*Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
As the number can be large, return the answer modulo 10^9+7.
Your Task:
You dont need to read input or print anything. Complete the function countStrings() which takes the integer N as the input parameter, and returns the number of binary strings of length N with no consecutive 1s.*/
#include <iostream>
using namespace std;
#define MOD 1000000007

class Solution {
public:
    typedef vector<vector<long long>> Matrix;

    Matrix multiply(Matrix A, Matrix B) {
        Matrix result = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix matrixExpo(Matrix base, long long power) {
        Matrix result = {{1, 0}, {0, 1}}; // Identity matrix
        while (power > 0) {
            if (power % 2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            power /= 2;
        }
        return result;
    }

    int countStrings(long long int N) {
        // We want the (N+2)th Fibonacci number
        if (N == 0) return 1;
        Matrix base = {{1, 1}, {1, 0}};
        Matrix result = matrixExpo(base, N + 1);
        return result[0][0]; // This holds Fib(N+2)
    }
};

// Main function to test the above code
int main() {
    Solution sol;
    long long int N1 = 3;
    long long int N2 = 2;

    cout << "Output for N = " << N1 << ": " << sol.countStrings(N1) << endl;
    cout << "Output for N = " << N2 << ": " << sol.countStrings(N2) << endl;

    return 0;
}
