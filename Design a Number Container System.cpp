/*Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
*/

#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
    unordered_map<int, unordered_set<int>> validIndices;

public:
    NumberContainers() {}

    void change(int index, int number) {
        // If index is already assigned a number, remove it from the previous number's valid indices
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int prevNumber = indexToNumber[index];
            validIndices[prevNumber].erase(index);
        }
        
        // Update the mappings
        indexToNumber[index] = number;
        numberToIndices[number].push(index);
        validIndices[number].insert(index);
    }

    int find(int number) {
        // If no valid indices exist for the number, return -1
        if (validIndices[number].empty()) {
            return -1;
        }

        // Remove outdated indices from the min-heap
        while (!numberToIndices[number].empty()) {
            int smallestIndex = numberToIndices[number].top();
            if (validIndices[number].count(smallestIndex)) {
                return smallestIndex; // Return the smallest valid index
            }
            numberToIndices[number].pop(); // Remove stale index
        }

        return -1;
    }
};

// Driver Code
int main() {
    NumberContainers nc;
    cout << nc.find(10) << endl; // -1
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    cout << nc.find(10) << endl; // 1
    nc.change(1, 20);
    cout << nc.find(10) << endl; // 2
    return 0;
}
