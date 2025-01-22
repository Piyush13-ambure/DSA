//Given an array are denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

//Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to find the maximum profit with multiple buy-sell transactions
    int stockBuySell(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0; // If there are less than 2 days, no profit can be made

        int maxProfit = 0;

        // Traverse the array to calculate the profit
        for (int i = 1; i < n; i++) {
            // If the price today is greater than the price yesterday, add the profit
            if (arr[i] > arr[i - 1]) {
                maxProfit += arr[i] - arr[i - 1];
            }
        }

        return maxProfit;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << solution.stockBuySell(prices1) << endl; // Output: 7

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum Profit: " << solution.stockBuySell(prices2) << endl; // Output: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum Profit: " << solution.stockBuySell(prices3) << endl; // Output: 0

    vector<int> prices4 = {1, 5, 3, 8, 12};
    cout << "Maximum Profit: " << solution.stockBuySell(prices4) << endl; // Output: 13

    return 0;
}
