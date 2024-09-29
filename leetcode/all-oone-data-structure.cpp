// 432. All O`one Data Structure
// https://leetcode.com/problems/all-oone-data-structure/

#include <bits/stdc++.h>

using namespace std;


// The idea is from Editorial's Approach: Using Doubly Linked List. The implementation is different.
class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        list<pair<int, unordered_set<string>>>::iterator old_it, new_it, next_it;
        int freq;

        if (keys.find(key) == keys.end()) {
            next_it = storage.begin();
            freq = 1;
        }
        else {
            old_it = keys[key];
            next_it = next(old_it);
            freq = old_it->first + 1;

            if (old_it->second.size() == 1)
                storage.erase(old_it);
            else
                old_it->second.erase(key);
        }
       
        if (next_it != storage.end() && next_it->first == freq) {
            next_it->second.emplace(key);
            new_it = next_it;
        }
        else {
            pair<int, unordered_set<string>> p(freq, {key});
            new_it = storage.emplace(next_it, p);
        }

        keys[key] = new_it;
    }
    
    void dec(string key) {
        list<pair<int, unordered_set<string>>>::iterator old_it, new_it, prev_it;

        old_it = keys[key];
        int freq = old_it->first;
        
        if (freq == 1) {
            keys.erase(key);
        }
        else {
            if (old_it == storage.begin()) {
                pair<int, unordered_set<string>> p(freq - 1, {key});
                storage.emplace_front(p);
                new_it = storage.begin();
            }
            else {
                prev_it = prev(old_it);
                if (prev_it->first == freq - 1) {
                    prev_it->second.emplace(key);
                    new_it = prev_it;
                }
                else {
                    pair<int, unordered_set<string>> p(freq - 1, {key});
                    new_it = storage.emplace(old_it, p);
                }
            }
            keys[key] = new_it;
        }

        if (old_it->second.size() == 1)
            storage.erase(old_it);
        else
            old_it->second.erase(key);
    }
    
    string getMaxKey() {
        if (storage.empty())
            return "";
        return *(storage.back().second.begin());
    }
    
    string getMinKey() {
        if (storage.empty())
            return "";
        return *(storage.front().second.begin());
    }

private:
    // <frequency, keys>; increasing order
    list<pair<int, unordered_set<string>>> storage;
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> keys;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
