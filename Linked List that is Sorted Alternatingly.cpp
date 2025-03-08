//You are given a Linked list. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.




#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* sort(Node* head) {
        if (!head || !head->next) return head;

        // Step 1: Split the list into two lists
        Node* asc = head;
        Node* desc = head->next;
        Node* ascPtr = asc;
        Node* descPtr = desc;

        while (ascPtr->next && descPtr->next) {
            ascPtr->next = descPtr->next;
            ascPtr = ascPtr->next;
            if (ascPtr->next) {
                descPtr->next = ascPtr->next;
                descPtr = descPtr->next;
            }
        }
        ascPtr->next = nullptr;
        descPtr->next = nullptr;

        // Step 2: Reverse the descending list
        desc = reverseList(desc);

        // Step 3: Merge two sorted lists
        return mergeSortedLists(asc, desc);
    }

private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* mergeSortedLists(Node* l1, Node* l2) {
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 && l2) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a node at the end
Node* insert(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
    return head;
}

int main() {
    // Creating the given linked list: 13->99->21->80->50
    Node* head = nullptr;
    head = insert(head, 13);
    head = insert(head, 99);
    head = insert(head, 21);
    head = insert(head, 80);
    head = insert(head, 50);

    cout << "Original List: ";
    printList(head);

    // Sorting the linked list
    Solution sol;
    head = sol.sort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
