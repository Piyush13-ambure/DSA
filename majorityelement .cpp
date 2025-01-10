//Given an array arr. Find the majority element in the array. If no majority exists, return -1.

//A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.
//  main.cpp
//  majorityelement
//
//  Created by piyush ambure on 10/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the majority element
    int majorityElement(const vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Boyer-Moore Voting Algorithm
        int candidate = -1, count = 0;
        
        // Find the candidate for majority element
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        // Step 2: Verify if the candidate is indeed the majority element
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }
        
        // Check if the candidate appears more than n/2 times
        if (count > n / 2) {
            return candidate;
        }
        
        return -1;  // No majority element
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Create a Solution object and call majorityElement
    Solution sol;
    int result = sol.majorityElement(arr);
    
    // Output the result
    if (result == -1) {
        cout << "No majority element exists." << endl;
    } else {
        cout << "The majority element is: " << result << endl;
    }
    
    return 0;
}
