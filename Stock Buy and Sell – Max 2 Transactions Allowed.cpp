//In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made. You are given an array arr[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &arr) {
        if (arr.empty()) return 0;

        int firstBuy = INT_MAX, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int price : arr) {
            firstBuy = min(firstBuy, price);           // Best price to buy first stock
            firstSell = max(firstSell, price - firstBuy); // Best profit after first sell
            secondBuy = max(secondBuy, firstSell - price); // Best price to buy second stock
            secondSell = max(secondSell, secondBuy + price); // Best profit after second sell
        }

        return secondSell;
    }
};

// Main function to test the implementation
int main() {
    int n;
    cout << "Enter number of stock prices: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << "Maximum Profit: " << obj.maxProfit(arr) << endl;

    return 0;
}
