//Given an array arr[] such that each element is in the range [0, 9] find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minSum(vector<int>& arr) {
        // Sort the array in non-decreasing order
        sort(arr.begin(), arr.end());

        // Form two numbers by alternately placing the digits
        string num1 = "", num2 = "";
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                num1 += to_string(arr[i]);
            } else {
                num2 += to_string(arr[i]);
            }
        }

        // Remove leading zeroes from the two numbers
        while (num1.length() > 1 && num1[0] == '0') {
            num1.erase(num1.begin());
        }
        while (num2.length() > 1 && num2[0] == '0') {
            num2.erase(num2.begin());
        }

        // Return the sum of the two numbers as a string
        return num1 + num2;
    }
};

int main() {
    vector<int> arr = {3, 2, 1, 4, 5};
    Solution sol;
    string result = sol.minSum(arr);
    cout << "Minimum sum: " << result << endl;

    return 0;
}
