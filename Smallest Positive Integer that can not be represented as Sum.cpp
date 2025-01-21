//Given an array of size N, find the smallest positive integer value that is either not presented in the array or cannot be represented as a sum(coz sum means you are adding two or more elements) of some elements from the array.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long smallestpositive(vector<long long> array, int n) {
        // Step 1: Sort the array
        sort(array.begin(), array.end());

        long long smallest = 1; // The smallest positive integer we are looking for

        // Step 2: Iterate through the array
        for (int i = 0; i < n; i++) {
            // If the current element is greater than 'smallest', it means 'smallest' is missing
            if (array[i] > smallest) {
                return smallest;
            }
            // Otherwise, add the current element to 'smallest'
            smallest += array[i];
        }

        // Step 3: If all elements are processed, return 'smallest'
        return smallest;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<long long> array1 = {1, 2, 3, 10};
    cout << "Smallest positive missing integer: " << solution.smallestpositive(array1, array1.size()) << endl;

    vector<long long> array2 = {1, 1, 3, 4};
    cout << "Smallest positive missing integer: " << solution.smallestpositive(array2, array2.size()) << endl;

    vector<long long> array3 = {1, 2, 2, 5, 7};
    cout << "Smallest positive missing integer: " << solution.smallestpositive(array3, array3.size()) << endl;

    return 0;
}

