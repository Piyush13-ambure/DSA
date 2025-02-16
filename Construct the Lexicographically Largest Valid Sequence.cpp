/*Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> sequence(size, -1);
        vector<bool> used(n + 1, false); // Track numbers placed
        backtrack(sequence, used, 0, n);
        return result;
    }

private:
    bool backtrack(vector<int>& sequence, vector<bool>& used, int index, int n) {
        int size = sequence.size();
        
        // If we filled the sequence, store result and return true
        if (index == size) {
            result = sequence;
            return true;
        }

        // If position is occupied, move to the next
        if (sequence[index] != -1) return backtrack(sequence, used, index + 1, n);

        // Try placing numbers from `n` down to `1`
        for (int i = n; i >= 1; i--) {
            if (used[i]) continue; // Skip already placed numbers
            
            // Place 1 in the first available position
            if (i == 1) {
                sequence[index] = 1;
                used[1] = true;
                if (backtrack(sequence, used, index + 1, n)) return true;
                sequence[index] = -1;
                used[1] = false;
            } 
            // Place `i` at `index` and `index + i` (if possible)
            else if (index + i < size && sequence[index] == -1 && sequence[index + i] == -1) {
                sequence[index] = sequence[index + i] = i;
                used[i] = true;
                if (backtrack(sequence, used, index + 1, n)) return true;
                sequence[index] = sequence[index + i] = -1;
                used[i] = false;
            }
        }
        return false; // No valid placement found
    }
};

// Driver function
int main() {
    Solution solution;

    int n1 = 3;
    vector<int> result1 = solution.constructDistancedSequence(n1);
    cout << "Output for n = 3: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    int n2 = 5;
    vector<int> result2 = solution.constructDistancedSequence(n2);
    cout << "Output for n = 5: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
