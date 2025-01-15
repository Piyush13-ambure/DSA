//Given an array of positive integers. Your task is to rearrange the array elements alternatively i.e. first element should be the max value, the second should be the min value, the third should be the second max, the fourth should be the second min, and so on.
//Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything
//  main.cpp
//  rearrange array alternately
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;

        int max_element = arr[n - 1] + 1; // One greater than the max element in the array
        int max_index = n - 1; // Pointer to the maximum element
        int min_index = 0;     // Pointer to the minimum element

        // Traverse the array
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // Place the maximum element
                arr[i] += (arr[max_index] % max_element) * max_element;
                max_index--;
            } else {
                // Place the minimum element
                arr[i] += (arr[min_index] % max_element) * max_element;
                min_index++;
            }
        }

        // Decode the new values
        for (int i = 0; i < n; i++) {
            arr[i] /= max_element;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    sol.rearrange(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

