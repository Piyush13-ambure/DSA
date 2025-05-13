/*Given an array arr[] of size, N. Find the subarray with maximum XOR. A subarray is a contiguous part of the array.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSubarrayXOR() which takes the array arr[], its size N as input parameters and returns the maximum xor of any subarray.
 */

#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];
    
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
    TrieNode* root;

    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }

    int query(int num) {
        TrieNode* curr = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->child[1 - bit]) {
                maxXor |= (1 << i);
                curr = curr->child[1 - bit];
            } else {
                curr = curr->child[bit];
            }
        }
        return maxXor;
    }

public:
    int maxSubarrayXOR(int N, int arr[]) {
        root = new TrieNode();
        insert(0); // Base case: prefix XOR is 0
        int result = 0;
        int prefixXOR = 0;
        
        for (int i = 0; i < N; i++) {
            prefixXOR ^= arr[i];
            result = max(result, query(prefixXOR));
            insert(prefixXOR);
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Output: " << sol.maxSubarrayXOR(n1, arr1) << endl;

    int arr2[] = {1, 4, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Output: " << sol.maxSubarrayXOR(n2, arr2) << endl;

    return 0;
}
