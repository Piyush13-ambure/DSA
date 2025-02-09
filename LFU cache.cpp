/*Design and implement an LFU (Least Frequently Used) cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types GET(x) and PUT(x, y). 

The LRU cache should support the following operations:

LFUCache(cap): initializes the cache with a given capacity.
get(key): returns the value associated with the key if it exists; otherwise, returns -1.
put(key, value): inserts or updates the key with value. If the cache has reached its capacity, the least frequently used (LFU) key should be removed. If there is a tie between keys with the same frequency, the least recently used (LRU) key among them should be removed.
*/


#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, int> keyToVal;  // {key -> value}
    unordered_map<int, int> keyToFreq; // {key -> frequency}
    unordered_map<int, list<int>> freqToKeys; // {frequency -> list of keys}
    unordered_map<int, list<int>::iterator> keyToIter; // {key -> iterator in freqToKeys}

    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end())
            return -1;
        updateFrequency(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = value;
            updateFrequency(key);
            return;
        }

        if (keyToVal.size() >= capacity) {
            evictLFU();
        }

        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        keyToIter[key] = --freqToKeys[1].end();
        minFreq = 1;
    }

private:
    void updateFrequency(int key) {
        int freq = keyToFreq[key];
        freqToKeys[freq].erase(keyToIter[key]);

        if (freqToKeys[freq].empty() && freq == minFreq)
            minFreq++;

        keyToFreq[key]++;
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = --freqToKeys[freq + 1].end();
    }

    void evictLFU() {
        int keyToRemove = freqToKeys[minFreq].front();
        freqToKeys[minFreq].pop_front();
        keyToVal.erase(keyToRemove);
        keyToFreq.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
    }
};
