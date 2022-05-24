// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// https://leetcode.com/problems/lru-cache/discuss/2068219/Simple-C%2B%2B-STL-implementation-using-list-and-unordered_map

#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    list<pair<int, int>> entries;
    unordered_map<int, list<pair<int, int>>::iterator> keys;
    int capacity;
           
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (keys.find(key) == keys.end()) {
            return -1;
        }
        entries.splice(entries.begin(), entries, keys[key]);
        keys[key] = entries.begin();
        return keys[key]->second;
    }
    
    void put(int key, int value) {
        
        if (keys.find(key) != keys.end()) {
            list<pair<int, int>>::iterator it = keys[key];
            entries.erase(it);
            keys.erase(key);
        }
        if (entries.size() == capacity) {
            int key_to_delete = entries.back().first;
            keys.erase(key_to_delete);
            entries.pop_back();
        }
        entries.push_front(pair<int, int>(key, value));
        keys[key] = entries.begin();
    }
};


int main () {



    return 0;
}
