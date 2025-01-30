//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // Dummy node to simplify list creation
        ListNode* current = &dummy;  // Pointer to track result list
        int carry = 0;  // To store carry value

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;  // Update carry for next iteration
            current->next = new ListNode(sum % 10);  // Store last digit
            current = current->next;
        }

        return dummy.next;  // Return the result list (skip dummy node)
    }
};

// Helper function to create a linked list from vector
ListNode* createLinkedList(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    Solution sol;
    
    // Example: 342 + 465 = 807 (stored in reverse order)
    ListNode* l1 = createLinkedList({2, 4, 3});
    ListNode* l2 = createLinkedList({5, 6, 4});
    
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printLinkedList(result);  // Expected Output: 7 -> 0 -> 8

    return 0;
}
