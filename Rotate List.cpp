/*Given the head of a linked list, rotate the list to the right by k places.

 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Edge cases

        // Step 1: Find the length of the list
        int n = 1; // At least one node exists
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Compute the effective k value
        k = k % n;
        if (k == 0) return head; // No change needed
        
        // Step 3: Find the new tail (n - k - 1th node)
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Step 4: Update pointers to make the new head and break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // Break the old list
        tail->next = head; // Connect tail to old head (circular link)

        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the rotation function
int main() {
    // Example 1: [1,2,3,4,5] rotated by 2 -> [4,5,1,2,3]
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution sol;
    ListNode* result1 = sol.rotateRight(head1, 2);
    printList(result1);

    // Example 2: [0,1,2] rotated by 4 -> [2,0,1]
    ListNode* head2 = new ListNode(0, new ListNode(1, new ListNode(2)));
    ListNode* result2 = sol.rotateRight(head2, 4);
    printList(result2);

    return 0;
}
