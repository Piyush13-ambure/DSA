/*Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                ++curr;
            }
        }
        return result;
    }
};

// ------------------- Main Function -------------------
int main() {
    Solution sol;
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> output = sol.lexicalOrder(n);
    cout << "Lexicographical Order: ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
