/*Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.*/
class Solution {
  public:
    // Comparison function to sort by value-to-weight ratio
    static bool compare(vector<int>& a, vector<int>& b) {
        double a1 = (1.0 * a[0]) / a[1];
        double b1 = (1.0 * b[0]) / b[1];
        return a1 > b1;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // Create 2D vector to store value and weight
        // items[i][0] = value, items[i][1] = weight
        vector<vector<int>> items(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            items[i][0] = val[i];
            items[i][1] = wt[i];
        }

        // Sort items based on value-to-weight ratio in descending order
        sort(items.begin(), items.end(), compare);

        double res = 0.0;
        int currentCapacity = capacity;

        // Process items in sorted order
        for (int i = 0; i < n; i++) {
            // If we can take the entire item
            if (items[i][1] <= currentCapacity) {
                res += items[i][0];
                currentCapacity -= items[i][1];
            }
            // Otherwise take a fraction of the item
            else {
                res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
                break; // Knapsack is full
            }
        }
        return res;
    }
};
