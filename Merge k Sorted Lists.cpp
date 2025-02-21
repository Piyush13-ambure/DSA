/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.*/


#include <iostream>
#include <vector>
#include <queue>
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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Insert the head of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) minHeap.push(list);
        }

        // Dummy head to track the start of merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            // Extract the smallest node
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            // Attach it to the result list
            tail->next = minNode;
            tail = tail->next;

            // If there are more nodes in the list, push the next node into the heap
            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        return dummy->next; // Return merged list (excluding dummy node)
    }
};

// Function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver Code
int main() {
    Solution sol;
    
    vector<ListNode*> lists = {
        createLinkedList({1, 4, 5}),
        createLinkedList({1, 3, 4}),
        createLinkedList({2, 6})
    };
    
    ListNode* mergedList = sol.mergeKLists(lists);
    printLinkedList(mergedList); // Expected Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 -> NULL
    
    return 0;
}
