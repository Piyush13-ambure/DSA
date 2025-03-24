/*Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.*/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;

        // Count the total number of nodes
        Node* temp = head;
        int totalNodes = 0;
        while (temp) {
            totalNodes++;
            temp = temp->next;
        }

        // Reverse in groups of k
        temp = head;
        Node* newHead = NULL;
        Node* prevTail = NULL;
        
        while (totalNodes >= k) {
            count = 0;
            curr = temp;
            prev = NULL;
            
            // Reverse k nodes
            while (count < k && curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            if (!newHead) {
                newHead = prev;  // New head after first reversal
            }
            if (prevTail) {
                prevTail->next = prev;  // Connect previous tail with new reversed head
            }
            prevTail = temp;  // Update tail
            temp = curr;
            totalNodes -= k;
        }

        // Attach the remaining nodes (if any)
        if (temp) {
            prevTail->next = NULL;
            prev = NULL;
            curr = temp;
            
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevTail->next = prev;
        }

        return newHead;
    }
};

/* Driver program to test above function */
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
