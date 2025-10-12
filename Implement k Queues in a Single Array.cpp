/*You are given two integers n and k. Your task is to implement a class kQueues that uses a single array of size n to simulate k independent queues.

The class should support the following operations:

enqueue(x, i) → Adds the element x into the i-th queue.
dequeue(i) → Removes the front element from the i-th queue and returns it. Returns -1 if the queue is empty.
isEmpty(i) → Returns true if i-th queue is empty, else return false.
isFull() → Returns true if the array is completely full and no more elements can be inserted, otherwise false.

There will be a sequence of q queries represented as:

1 x i : Call enqueue(x, i)
2 i : Call dequeue(i)
3 i : Call isEmpty(i)
4 : Call isFull()
The driver code will process the queries, call the corresponding functions, and print the results of dequeue, isEmpty, and isFull operations.
You only need to implement the above four functions.*/

class kQueues {
  private:
    vector<int> arr;
    int n, k;
    vector<int> front;
    vector<int> rear;
    vector<int> next;
    int freeIndex;

  public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n);

        // Initialize all spaces as free
        freeIndex = 0;
        for (int ind = 0; ind < n - 1; ind++)
            next[ind] = ind + 1;

        // -1 is used to indicate end of free list
        next[n - 1] = -1;
    }

    // Function to check if queue 'i' is empty
    bool isEmpty(int i) { return (front[i] == -1); }

    // Function to check if array is full
    bool isFull() { return (freeIndex == -1); }

    // Function to enqueue 'x' into queue 'i'
    void enqueue(int x, int i) {

        // Get next free index
        int ind = freeIndex;
        freeIndex = next[ind];

        // If queue is empty, update both front and rear
        if (isEmpty(i))
            front[i] = ind;
        else {
            // Link new element to the previous rear
            next[rear[i]] = ind;
        }

        // Update rear
        rear[i] = ind;

        // Store the element
        arr[ind] = x;

        // Mark end of queue
        next[ind] = -1;
    }

    // Function to dequeue from queue 'i'
    int dequeue(int i) {

        // Check if queue is empty
        if (isEmpty(i))
            return -1;

        // Get the front index of queue
        int ind = front[i];

        // Update front
        front[i] = next[ind];

        // If queue becomes empty
        if (front[i] == -1)
            rear[i] = -1;

        // Add the dequeued position to free list
        next[ind] = freeIndex;
        freeIndex = ind;

        // Return the dequeued element
        return arr[ind];
    }
};
