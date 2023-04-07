// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/

#include <bits/stdc++.h>

using namespace std;


// Combined ideas from the Leetcode's Editorial and Sample 90 ms submission
class MyHashMap {
public:
    MyHashMap() {
        storage.resize(1024);
    }
    
    void put(int key, int value) {
        int bucket = key % (sizeof(storage) / sizeof(storage[0]));
        for (auto& [pkey, pvalue]: storage[bucket])
            if (pkey == key) {
                pvalue = value;
                return;
            }
        storage[bucket].emplace_back(pair<int, int>(key, value));
    }
    
    int get(int key) {
        int bucket = key % (sizeof(storage) / sizeof(storage[0]));
        for (auto& [pkey, pvalue]: storage[bucket])
            if (pkey == key)
                return pvalue;
        return -1;
    }
    
    void remove(int key) {
        int bucket = key % (sizeof(storage) / sizeof(storage[0]));
        vector<pair<int, int>>::iterator it = storage[bucket].begin();
        while (it != storage[bucket].end()) {
            if ((*it).first == key) {
                storage[bucket].erase(it);
                return;
            }
            ++it;
        }
    }

private:
    vector<vector<pair<int, int>>> storage;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
