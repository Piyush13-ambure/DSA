//Given an array arr[] denoting heights of N towers and a positive integer K.

//For each tower, you must perform exactly one of the following operations exactly once.

//Increase the height of the tower by K Decrease the height of the tower by K
//Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
//  main.cpp
//  minimum height
//
//  Created by piyush ambure on 13/01/25.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int getMinDiff(vector<int>& arr, int k) {
        if (arr.size() <= 1) {
            return 0;
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int diff = arr[n - 1] - arr[0]; // Initial difference between the max and min heights

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        if (smallest > largest) {
            swap(smallest, largest);
        }

        for (int i = 1; i < n - 1; ++i) {
            int add = arr[i] + k;
            int subtract = arr[i] - k;

            if (subtract >= smallest || add <= largest) {
                continue;
            }

            if (largest - subtract <= add - smallest) {
                smallest = subtract;
            } else {
                largest = add;
            }
        }

        return min(diff, largest - smallest);
    }
};

int main() {
    Solution solution;
    int n, k;
    cout << "Enter the number of towers: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of towers!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the heights of the towers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> k;

    int result = solution.getMinDiff(arr, k);
    cout << "The minimum possible difference is: " << result << endl;

    return 0;
}
