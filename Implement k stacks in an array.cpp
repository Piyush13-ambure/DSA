/*You are given two integers n and k. Your task is to implement a class kStacks that uses a single array of size n to simulate k independent stacks.
The class should support the following operations:

push(x, i) – Push element x into the i-th stack.
pop(i) – Pop the top element from the i-th stack and return it. Return -1 if it is empty.
There will be a sequence of q queries queries[][]. The queries are represented in numeric form:

1 x i: Call push(x, i)
2 i:  Call pop(i)
The driver code will process the queries, call the corresponding functions, and print the outputs of pop(i) operations.
You only need to implement the above two functions.*/

class kStacks {

    // main array to store elements
    int *arr;

    // array to store indexes of top elements of stacks
    int *top;

    // array to store next entry (for free list and stack links)
    int *next;

    // beginning index of free list
    int freeTop;

  public:
    kStacks(int n, int k) {
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize tops of all stacks as empty
        for (int i = 0; i < k; i++)
            top[i] = -1;

        // initialize free list
        freeTop = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }

    // push element x into stack i
    void push(int x, int i) {

        // take index from free list
        int index = freeTop;

        // update free list
        freeTop = next[index];

        // put element in array
        arr[index] = x;

        // link new element to previous top
        next[index] = top[i];

        // update top of stack
        top[i] = index;
    }

    // pop element from stack i
    int pop(int i) {
        if (top[i] == -1) {
            return -1;
        }

        // get top index
        int index = top[i];

        // update top to next element
        top[i] = next[index];

        // add index back to free list
        next[index] = freeTop;
        freeTop = index;

        // return popped element
        return arr[index];
    }
};
