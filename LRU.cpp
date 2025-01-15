//
//  main.cpp
//  LRU cache
//
//  Created by piyush ambure on 15/01/25.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity; // Maximum capacity of the cache
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> hashMap; // Hash map for quick look-up

public:
    // Constructor to initialize the cache with a given capacity
    LRUCache(int cap) : capacity(cap) {}

    // Function to return value corresponding to the key
    int get(int key) {
        // If the key is not present in the cache
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        }
        // Move the accessed key-value pair to the front (most recently used)
        auto it = hashMap[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }

    // Function to store key-value pair
    void put(int key, int value) {
        // If the key is already present, update its value and move to the front
        if (hashMap.find(key) != hashMap.end()) {
            auto it = hashMap[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // If the cache is at full capacity, remove the least recently used item
        if (cache.size() == capacity) {
            auto last = cache.back();
            hashMap.erase(last.first);
            cache.pop_back();
        }

        // Insert the new key-value pair to the front
        cache.emplace_front(key, value);
        hashMap[key] = cache.begin();
    }
};

// Main function to demonstrate LRUCache
int main() {
    // Create a cache with a capacity of 3
    LRUCache lru(3);

    // Perform operations
    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);

    cout << "Get 1: " << lru.get(1) << endl; // Should return 10
    lru.put(4, 40); // Cache is full, removes least recently used (2)
    cout << "Get 2: " << lru.get(2) << endl; // Should return -1 (not found)
    cout << "Get 3: " << lru.get(3) << endl; // Should return 30
    lru.put(5, 50); // Cache is full, removes least recently used (1)
    cout << "Get 1: " << lru.get(1) << endl; // Should return -1 (not found)
    cout << "Get 4: " << lru.get(4) << endl; // Should return 40
    cout << "Get 5: " << lru.get(5) << endl; // Should return 50

    return 0;
}
