/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;
        
        while (true) {
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *groupEnd = prevGroupEnd;
            
            // Check if there are k nodes to reverse
            for (int i = 0; i < k && groupEnd; i++) {
                groupEnd = groupEnd->next;
            }
            if (!groupEnd) break; // Not enough nodes left to reverse
            
            // Reverse k nodes
            ListNode *prev = groupEnd->next, *curr = groupStart, *next = nullptr;
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Connect reversed group to previous part
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }
        
        return dummy->next;
    }
};
