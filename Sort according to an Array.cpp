/*Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
        unordered_map<int, int> freq;
        vector<int> remaining;
        
        // Count occurrences of each element in A1
        for (int num : A1) {
            freq[num]++;
        }
        
        vector<int> result;
        
        // Place elements of A1 according to A2 order
        for (int num : A2) {
            if (freq.count(num)) {
                while (freq[num] > 0) {
                    result.push_back(num);
                    freq[num]--;
                }
                freq.erase(num); // Remove processed element
            }
        }
        
        // Store remaining elements (not in A2) to sort later
        for (auto &pair : freq) {
            while (pair.second > 0) {
                remaining.push_back(pair.first);
                pair.second--;
            }
        }
        
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        
        // Append sorted remaining elements
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int> A2 = {2, 1, 8, 3};
    
    vector<int> sortedArray = sol.sortA1ByA2(A1, A1.size(), A2, A2.size());
    
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


