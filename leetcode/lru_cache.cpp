// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// https://leetcode.com/problems/lru-cache/discuss/2068219/Simple-C%2B%2B-STL-implementation-using-list-and-unordered_map

#include <bits/stdc++.h>

using namespace std;


class LRUCache {
public:
    LRUCache (int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        this->capacity = capacity;
    }

    int get(int key) {
        if (keys.find(key) == keys.end())
            return -1;
        auto it = keys[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            auto it = keys[key];
            cache.splice(cache.begin(), cache, it);
            cache.front().second = value;
            return;
        }
        if (cache.size() == capacity) {
            keys.erase(cache.back().first);
            cache.pop_back();
        }
        cache.emplace_front(pair<int, int>(key, value));
        keys[key] = cache.begin();
    }  

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> keys;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
