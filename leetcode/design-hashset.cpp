// 705. Design HashSet
// https://leetcode.com/problems/design-hashset/

#include <bits/stdc++.h>

using namespace std;


class MyHashSet {
public:
    MyHashSet() {
        storage.resize(2069);
    }
    
    void add(int key) {
        int bucket = key % 2069;
        for (const int& element: storage[bucket])
            if (element == key) 
                return;
        storage[bucket].emplace_back(key);
    }
    
    void remove(int key) {
        int bucket = key % 2069;
        for (auto it = storage[bucket].begin(); it < storage[bucket].end(); ++it)
            if (*it == key) {
                storage[bucket].erase(it);
                return;
            }
    }
    
    bool contains(int key) {
        int bucket = key % 2069;
        for (const int& element: storage[bucket])
            if (element == key)
                return true;
        return false;
    }

private:
    vector<vector<int>> storage;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
