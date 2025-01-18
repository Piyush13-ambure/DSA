//Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

//PUT x y: sets the value of the key x with value y
//GET x: gets the key of x if present else returns -1.
//The LRUCache class has two methods get() and put() which are defined as follows.

//get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
//put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
//In the constructor of the class the capacity of the cache should be initialized.     #include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    // Node structure for doubly linked list
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity; // Maximum capacity of the cache
    unordered_map<int, Node*> cache; // Hash map to store key-node mapping
    Node* head; // Dummy head of the doubly linked list
    Node* tail; // Dummy tail of the doubly linked list

    // Function to add a node right after the dummy head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Function to remove a node from the doubly linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Remove the least recently used node (node before the dummy tail)
    void removeLeastRecentlyUsed() {
        Node* lru = tail->prev;
        removeNode(lru);
        cache.erase(lru->key);
        delete lru;
    }

public:
    // Constructor for initializing the cache capacity
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        Node* node = cache[key];
        moveToFront(node); // Move the accessed node to the front
        return node->value;
    }

    // Function for storing key-value pair
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update its value and move it to the front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // Key does not exist, add a new node
            if (cache.size() == capacity) {
                // If capacity is full, remove the least recently used node
                removeLeastRecentlyUsed();
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
        }
    }

    // Destructor to clean up memory
    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function to test the LRUCache class
int main() {
    int capacity, queries;
    cout << "Enter the capacity of the cache: ";
    cin >> capacity;
    LRUCache lru(capacity);

    cout << "Enter the number of queries: ";
    cin >> queries;

    while (queries--) {
        string queryType;
        cout << "Enter query (GET x / PUT x y): ";
        cin >> queryType;

        if (queryType == "GET") {
            int key;
            cin >> key;
            int result = lru.get(key);
            cout << "GET " << key << " -> " << result << endl;
        } else if (queryType == "PUT") {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
            cout << "PUT " << key << " " << value << endl;
        } else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
