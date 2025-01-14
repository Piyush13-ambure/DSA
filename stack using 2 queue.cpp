//Implement a Stack using two queues q1 and q2.
//  main.cpp
//  stack using 2 queue
//
//  Created by piyush ambure on 14/01/25.
//

#include <iostream>
#include <queue>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
    
public:
    // Function to push an element into stack using two queues.
    void push(int x) {
        // Push the element into q2
        q2.push(x);
        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2 so that q1 has the correct stack order
        swap(q1, q2);
    }
    
    // Function to pop an element from stack using two queues.
    int pop() {
        if (q1.empty()) {
            return -1; // Stack is empty
        }
        
        // Pop the element from q1 (which is the stack's top element)
        int top = q1.front();
        q1.pop();
        return top;
    }
};

int main() {
    QueueStack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Pop: " << s.pop() << endl;  // Output: 30
    cout << "Pop: " << s.pop() << endl;  // Output: 20
    cout << "Pop: " << s.pop() << endl;  // Output: 10
    cout << "Pop: " << s.pop() << endl;  // Output: -1 (stack is empty)
    
    return 0;
}
