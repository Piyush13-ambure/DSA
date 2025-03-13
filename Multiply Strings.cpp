/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);  // Result array of size (m + n)

        // Reverse iterate through both strings for multiplication
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');  // Multiply digits
                int sum = mul + result[i + j + 1];  // Add to previous stored value

                result[i + j + 1] = sum % 10;  // Store unit place
                result[i + j] += sum / 10;     // Carry forward
            }
        }

        // Convert result array to string
        string product = "";
        for (int num : result) {
            if (!(product.empty() && num == 0)) {  // Skip leading zeros
                product += (num + '0');
            }
        }

        return product.empty() ? "0" : product;  // Handle edge case "0"
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    cout << "Output for 2 * 3: " << sol.multiply("2", "3") << endl;         // Expected: "6"
    cout << "Output for 123 * 456: " << sol.multiply("123", "456") << endl; // Expected: "56088"
    return 0;
}
