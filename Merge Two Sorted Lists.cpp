/*re given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 */


#include <bits/stdc++.h>
using namespace std;

// **Definition for singly-linked list.**
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Dummy node to simplify list merging
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining list if one is not exhausted
        tail->next = (list1) ? list1 : list2;

        return dummy.next;
    }
};

// **Helper function to create a linked list from vector**
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr, *tail = nullptr;
    for (int val : values) {
        if (!head) {
            head = tail = new ListNode(val);
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    return head;
}

// **Helper function to print a linked list**
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// **Main function to test the solution**
int main() {
    Solution sol;

    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    printList(mergedList);  // Expected Output: 1 1 2 3 4 4

    return 0;
}
