/*You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

NOTE : Original linked list should remain unchanged.*/
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node* root) {
    map<Node*, int> link;
    Node* temp = root;
    for (int i = 0; temp != NULL; i++) {
        link[temp] = i;
        temp = temp->next;
    }
    temp = root;
    cout << "[";
    while (temp->next != NULL) {
        if (!temp->random) {
            cout << "[" << temp->data << ", "
                 << "NULL"
                 << "], ";
        } else
            cout << "[" << temp->data << ", " << link[temp->random] + 1 << "], ";
        temp = temp->next;
    }
    if (!temp->random) {
        cout << "[" << temp->data << ", "
             << "NULL"
             << "]]\n";
    } else
        cout << "[" << temp->data << ", " << link[temp->random] + 1 << "]]\n";
}

bool validation(Node* res, map<Node*, int>& orgAddress) {
    Node* temp = res;
    for (int i = 0; temp != NULL; i++) {
        if (orgAddress.find(temp) != orgAddress.end()) {
            return false;
        }
        if (orgAddress.find(temp->random) != orgAddress.end()) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node* buildLinkedList(vector<pair<int, int>>& v, map<Node*, int>& orgAddress) {
    vector<Node*> address(v.size());
    Node* head = new Node(v[0].first);
    address[0] = head;
    Node* temp = head;
    orgAddress[head] = 0;
    for (int i = 1; i < v.size(); i++) {
        Node* newNode = new Node(v[i].first);
        orgAddress[newNode] = i;
        address[i] = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second != -1) {
            temp->random = address[v[i].second - 1];
        }
        temp = temp->next;
    }

    return head;
}

bool validateInput(map<Node*, int>& orgAddress, Node* head, vector<pair<int, int>>& v) {
    vector<Node*> address(v.size());
    Node* temp = head;
    for (int i = 0; i < v.size(); i++) {
        if (orgAddress.find(temp) == orgAddress.end() || orgAddress[temp] != i) {
            return false;
        }
        address[i] = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        return false;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++) {
        int value = v[i].first;
        int randomIndex = v[i].second;

        if (randomIndex == -1) {
            if (temp->random != NULL) {
                return false;
            }
        } else {
            Node* tempNode = address[randomIndex - 1];
            if (temp->random != tempNode) {
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}


class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return NULL;

        // Step 1: Insert clone nodes next to original nodes
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->data);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Set random pointers of the clone nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and cloned lists
        curr = head;
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;

        while (curr) {
            curr->next = curr->next->next;
            if (cloneCurr->next)
                cloneCurr->next = cloneCurr->next->next;
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
    }
};




int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n); // node data, random node number
        for (int i = 0; i < n; i++) {
            int x;
            string y;
            cin >> x >> y;
            if (y == "NULL" || y == "N" || y == "null" || y == "n" || y == "Null") {
                v[i] = {x, -1};
            } else {
                v[i] = {x, stoi(y)};
            }
        }
        map<Node*, int> orgAddress;
        Node* head = buildLinkedList(v, orgAddress);

        Solution ob;
        Node* res = ob.cloneLinkedList(head);
        // check if input modified.
        if (validateInput(orgAddress, head, v)) {
            if (validation(res, orgAddress)) {
                print(res);
            } else {
                cout << "Pointing to the original list\n";
            }
        } else {
            cout << "Input list modified\n";
        }
        cout << "~\n";
    }
    return 0;
}
