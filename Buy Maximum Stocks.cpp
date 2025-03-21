/*In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        // Store price with the respective day number
        vector<pair<int, int>> stocks;
        for (int i = 0; i < n; i++) {
            stocks.push_back({price[i], i + 1});
        }
        
        // Sort by price in ascending order
        sort(stocks.begin(), stocks.end());
        
        int totalStocks = 0;
        
        // Buy stocks greedily
        for (auto &stock : stocks) {
            int costPerStock = stock.first;
            int maxStocksBuyable = stock.second; // max we can buy on that day
            
            // Buy the minimum of maxStocksBuyable or what we can afford
            int stocksBought = min(maxStocksBuyable, k / costPerStock);
            
            totalStocks += stocksBought;
            k -= stocksBought * costPerStock;  // Deduct cost
            
            if (k <= 0) break; // Stop if no money left
        }
        
        return totalStocks;
    }
};

// Driver Code
int main() {
    Solution obj;
    
    int price1[] = {10, 7, 19};
    int k1 = 45;
    cout << obj.buyMaximumProducts(3, k1, price1) << endl; // Output: 4
    
    int price2[] = {7, 10, 4};
    int k2 = 100;
    cout << obj.buyMaximumProducts(3, k2, price2) << endl; // Output: 6
    
    return 0;
}
