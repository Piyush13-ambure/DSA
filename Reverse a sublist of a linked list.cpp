/*Given a linked list and positions a and b. Reverse the linked list from position a to b and return the head of the resultant linked list.*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        if (!head || a == b) {
            return head;
        }

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* pre = dummy;

        for (int i = 1; i < a; ++i) {
            pre = pre->next;
        }

        Node* curr = pre->next;
        Node* nextNode = nullptr;
        Node* prev = nullptr;

        for (int i = 0; i <= (b - a); ++i) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        pre->next->next = curr;
        pre->next = prev;

        return dummy->next;
    }
};

int main() {
    // Example usage:
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Solution sol;
    Node* reversedHead = sol.reverseBetween(2, 4, head);

    // Print the reversed linked list
    Node* current = reversedHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up memory (important to prevent memory leaks)
    current = reversedHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
