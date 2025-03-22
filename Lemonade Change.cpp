/*You are an owner of lemonade island, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers.

Given an integer array bills of size N where bills [ i ] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int five = 0, ten = 0; // To store the count of $5 and $10 bills
        
        for (int bill : bills) {
            if (bill == 5) {
                five++; // Directly collect the $5 bill
            } 
            else if (bill == 10) {
                if (five > 0) {
                    five--; // Give back one $5 bill as change
                    ten++;  // Store the $10 bill
                } else {
                    return false; // No $5 bill to give as change
                }
            } 
            else { // bill == 20
                if (ten > 0 && five > 0) { 
                    ten--; // Give back one $10 bill
                    five--; // Give back one $5 bill
                } 
                else if (five >= 3) {
                    five -= 3; // Give back three $5 bills
                } 
                else {
                    return false; // Not enough change
                }
            }
        }
        
        return true; // All customers received the correct change
    }
};

// Main function for testing
int main() {
    Solution sol;
    
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << (sol.lemonadeChange(5, bills1) ? "True" : "False") << endl; // Expected output: True

    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << (sol.lemonadeChange(5, bills2) ? "True" : "False") << endl; // Expected output: False

    return 0;
}
