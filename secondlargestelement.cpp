//
// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.Note: The second largest element should not be equal to the largest element.
//
//  Created by piyush ambure on 08/01/25.
//
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int findSecondLargest(const vector<int>& arr) {
        int largest = INT_MIN, secondLargest = INT_MIN;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num < largest) {
                secondLargest = num;
            }
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int secondLargest = solution.findSecondLargest(arr);
    cout << "The second largest element is: " << secondLargest << endl;

    return 0;
}
