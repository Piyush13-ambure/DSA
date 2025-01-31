//You are given a string initialCurrency, and you start with 1.0 of initialCurrency.

//You are also given four arrays with currency pairs (strings) and rates (real numbers):

//pairs1[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates1[i] on day 1.
//pairs2[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates2[i] on day 2.
//Also, each targetCurrency can be converted back to its corresponding startCurrency at a rate of 1 / rate.
//You can perform any number of conversions, including zero, using rates1 on day 1, followed by any number of additional conversions, including zero, using rates2 on day 2.

//Return the maximum amount of initialCurrency you can have after performing any number of conversions on both days in order.

//Note: Conversion rates are valid, and there will be no contradictions in the rates for either day. The rates for the days are independent of each other.


#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to build adjacency list for the given currency pairs
    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = pairs.size();
        for (int i = 0; i < n; i++) {
            string from = pairs[i][0], to = pairs[i][1];
            double rate = rates[i];

            graph[from].push_back({to, rate});
            graph[to].push_back({from, 1.0 / rate});
        }
        return graph;
    }

    // Function to find the maximum values for each currency using BFS
    unordered_map<string, double> bfsMaxConversion(string start, unordered_map<string, vector<pair<string, double>>>& graph) {
        unordered_map<string, double> maxAmount;
        queue<string> q;

        maxAmount[start] = 1.0; // Start with 1.0 of initialCurrency
        q.push(start);

        while (!q.empty()) {
            string currency = q.front();
            q.pop();

            for (auto& [nextCurrency, rate] : graph[currency]) {
                double newAmount = maxAmount[currency] * rate;
                if (newAmount > maxAmount[nextCurrency]) {
                    maxAmount[nextCurrency] = newAmount;
                    q.push(nextCurrency);
                }
            }
        }
        return maxAmount;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        // Step 1: Build Graphs for both days
        auto graph1 = buildGraph(pairs1, rates1);
        auto graph2 = buildGraph(pairs2, rates2);

        // Step 2: Run BFS for Day 1 conversions
        auto day1Amounts = bfsMaxConversion(initialCurrency, graph1);

        // Step 3: Run BFS for Day 2 using maximum amounts from Day 1
        double maxFinalAmount = 1.0;
        for (auto& [currency, amount] : day1Amounts) {
            auto day2Amounts = bfsMaxConversion(currency, graph2);
            if (day2Amounts.find(initialCurrency) != day2Amounts.end()) {
                maxFinalAmount = max(maxFinalAmount, amount * day2Amounts[initialCurrency]);
            }
        }

        return maxFinalAmount;
    }
};

// Example usage
int main() {
    Solution sol;
    
    string initialCurrency = "USD";
    vector<vector<string>> pairs1 = {{"USD", "EUR"}, {"EUR", "GBP"}};
    vector<double> rates1 = {0.9, 1.2};

    vector<vector<string>> pairs2 = {{"EUR", "JPY"}, {"JPY", "GBP"}};
    vector<double> rates2 = {130, 0.0077};

    double result = sol.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2);
    cout << result << endl; // Output: Maximum amount of USD after both days

    return 0;
}
