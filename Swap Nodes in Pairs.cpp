//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <bits/stdc++.h>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);  // Dummy node before head
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;        // First node of the pair
            ListNode* second = prev->next->next; // Second node of the pair

            // Swap nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};

// Utility function to create a linked list from a vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 2, 3, 4};
    ListNode* head1 = createList(arr1);
    printList(sol.swapPairs(head1)); // Output: 2 1 4 3
    
    vector<int> arr2 = {1, 2, 3};
    ListNode* head2 = createList(arr2);
    printList(sol.swapPairs(head2)); // Output: 2 1 3
    
    vector<int> arr3 = {};
    ListNode* head3 = createList(arr3);
    printList(sol.swapPairs(head3)); // Output: (empty)

    vector<int> arr4 = {1};
    ListNode* head4 = createList(arr4);
    printList(sol.swapPairs(head4)); // Output: 1

    return 0;
}
