//Given a queue q containing integer elements, your task is to reverse the queue.
//  main.cpp
//  queue reverse
//
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to reverse the queue
    queue<int> reverseQueue(queue<int>& q) {
        // Base case: if the queue is empty, return the empty queue
        if (q.empty()) {
            return q;
        }

        // Step 1: Dequeue the front element
        int front = q.front();
        q.pop();

        // Step 2: Recursively reverse the rest of the queue
        queue<int> reversedQueue = reverseQueue(q);

        // Step 3: Push the front element to the back of the reversed queue
        reversedQueue.push(front);

        // Return the reversed queue
        return reversedQueue;
    }
};

// Driver code
int main() {
    Solution solution;
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    queue<int> reversedQueue = solution.reverseQueue(q);
    
    // Print reversed queue
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }

    return 0;
}
