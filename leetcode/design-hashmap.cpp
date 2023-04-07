// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/

#include <bits/stdc++.h>

using namespace std;


class MyHashMap {
public:
    MyHashMap() {
        storage.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        storage[key] = value;
    }
    
    int get(int key) {
        return storage[key];
    }
    
    void remove(int key) {
        storage[key] = -1;
    }

private:
    vector<int> storage;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
