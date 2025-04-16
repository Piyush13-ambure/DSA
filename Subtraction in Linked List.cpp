/*You are given two linked lists representing two large positive numbers. The linked lists represent these two numbers, subtract the smaller number from the larger one and return the head of the linked list representing the result. Please take a look at the examples to get a better understanding of the task.

The linked list does not contain leading zeros, except for the number zero itself.*/



#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Solution class
class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0 && head->next)
            head = head->next;
        return head;
    }

    bool isGreaterOrEqual(Node* head1, Node* head2) {
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        while (temp1) { len1++; temp1 = temp1->next; }
        while (temp2) { len2++; temp2 = temp2->next; }

        if (len1 != len2)
            return len1 > len2;

        temp1 = head1;
        temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->data != temp2->data)
                return temp1->data > temp2->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        if (!isGreaterOrEqual(head1, head2))
            std::swap(head1, head2);

        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* p1 = head1;
        Node* p2 = head2;
        int borrow = 0;

        while (p1) {
            int d1 = p1->data;
            int d2 = (p2 ? p2->data : 0);
            int sub = d1 - d2 - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            temp->next = new Node(sub);
            temp = temp->next;
            p1 = p1->next;
            if (p2) p2 = p2->next;
        }

        Node* result = reverse(dummy->next);
        result = removeLeadingZeros(result);
        return result;
    }
};

// Helper to create a linked list from a vector of digits
Node* createList(const vector<int>& digits) {
    if (digits.empty()) return NULL;
    Node* head = new Node(digits[0]);
    Node* temp = head;
    for (size_t i = 1; i < digits.size(); ++i) {
        temp->next = new Node(digits[i]);
        temp = temp->next;
    }
    return head;
}

// Helper to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Example: 100 - 99 = 1
    vector<int> num1 = {1, 0, 0}; // Represents 100
    vector<int> num2 = {9, 9};    // Represents 99

    Node* head1 = createList(num1);
    Node* head2 = createList(num2);

    Solution sol;
    Node* result = sol.subLinkedList(head1, head2);

    cout << "Result: ";
    printList(result);

    return 0;
}

