/*Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> result;
        priority_queue<int> left; // Max heap for smaller numbers
        priority_queue<int, vector<int>, greater<int>> right; // Min heap for larger numbers

        for (int num : arr) {
            // Insert into appropriate heap
            if (left.empty() || num <= left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }

            // Balance heaps
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            // Get median
            if (left.size() > right.size()) {
                result.push_back(left.top());
            } else {
                result.push_back((left.top() + right.top()) / 2.0);
            }
        }

        return result;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> arr = {5, 15, 1, 3};
    vector<double> medians = sol.getMedian(arr);

    cout << "Medians: ";
    for (double median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}
