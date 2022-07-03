// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// https://leetcode.com/problems/lru-cache/discuss/2068219/Simple-C%2B%2B-STL-implementation-using-list-and-unordered_map

#include <bits/stdc++.h>

using namespace std;


class LRUCache {
public:    
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (keys.find(key) != keys.end()) {
            auto it = keys[key];
            cache.splice(cache.begin(), cache, it);
            return it -> second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            auto it = keys[key];
            cache.erase(it);
            keys.erase(key);
        }
        if (cache.size() == capacity_) {
            keys.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        keys[key] = cache.begin();
    }
private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> keys;
    list<pair<int, int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
