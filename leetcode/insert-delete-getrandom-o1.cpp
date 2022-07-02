// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <bits/stdc++.h>

using namespace std;


class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        mp[val] = v.size();
        v.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        mp[v.back()] = mp[val];
        swap(v[mp[val]], v[v.size() - 1]);
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> distrib(0, v.size() - 1);
        int random_index = distrib(rd);
        return v[random_index];
    }
private:
    vector<int> v;
    unordered_map<int, int> mp;
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    random_device rd;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
