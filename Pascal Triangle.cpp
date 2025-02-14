//Given a positive integer n, return the nth row of pascal's triangle.
//Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n, 1);
        for (int i = 1; i < n - 1; i++) {
            row[i] = (row[i - 1] * (n - i)) / i;
        }
        return row;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.nthRowOfPascalTriangle(n);

    cout << "The " << n << "th row of Pascal's Triangle is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


