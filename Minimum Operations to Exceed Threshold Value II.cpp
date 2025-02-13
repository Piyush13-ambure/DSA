/*You are given a 0-indexed integer array nums, and an integer k.

In one operation, you will:

Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.*/




#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.top() < k) {
            // Extract the two smallest elements
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();

            // Compute the new value
            int newValue = (min(x, y) * 2) + max(x, y);
            minHeap.push(newValue);

            // Increment operation count
            operations++;
        }

        return operations;
    }
};

int main() {
    Solution solution;
    int n, k;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    int result = solution.minOperations(nums, k);
    cout << "Minimum operations needed: " << result << endl;
    
    return 0;
}
