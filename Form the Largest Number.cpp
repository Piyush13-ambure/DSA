//Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findLargest(vector<int>& arr) {
        // Convert integers to strings for custom sorting
        vector<string> strArr;
        for (int num : arr) {
            strArr.push_back(to_string(num));
        }

        // Custom comparator: compare concatenated results to determine order
        sort(strArr.begin(), strArr.end(), [](string &a, string &b) {
            return a + b > b + a; // Concatenate and compare
        });

        // If the largest number is "0", return "0" (e.g., all elements are 0)
        if (strArr[0] == "0") {
            return "0";
        }

        // Concatenate all strings to form the largest number
        string result;
        for (string &s : strArr) {
            result += s;
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    string result = sol.findLargest(arr);

    cout << "The largest possible number is: " << result << "\n";

    return 0;
}
