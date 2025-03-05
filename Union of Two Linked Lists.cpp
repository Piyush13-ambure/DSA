//Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.



//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}



class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        set<int> uniqueElements;

        // Traverse first list and insert elements into the set
        while (head1) {
            uniqueElements.insert(head1->data);
            head1 = head1->next;
        }

        // Traverse second list and insert elements into the set
        while (head2) {
            uniqueElements.insert(head2->data);
            head2 = head2->next;
        }

        // Create a new linked list from the sorted set
        Node* newHead = nullptr;
        Node* tail = nullptr;
        
        for (int val : uniqueElements) {
            Node* newNode = new Node(val);
            if (!newHead) {
                newHead = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        return newHead;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
