// 2502. Design Memory Allocator
// https://leetcode.com/problems/design-memory-allocator/

#include <bits/stdc++.h>

using namespace std;


class Allocator {
public:
    Allocator(int n) {
        this->n = n;
        memory.emplace(memory.end(), pair<int, int>(0, 0));   // pre-head
        memory.emplace(memory.end(), pair<int, int>(n, n));   // post-tail
    }
    
    int allocate(int size, int mID) {
        auto left_it = memory.begin(), right_it = memory.begin();
        ++right_it;
        while (right_it != memory.end()) {
            int left = left_it->second, right = right_it->first;
            if (right - left >= size) {
                auto new_block_it = memory.emplace(right_it, pair<int, int>(left, left + size));
                blocks[mID].emplace_back(new_block_it);
                return left;
            }
            ++left_it;
            ++right_it;
        }
        return -1;
    }
    
    int free(int mID) {
        if (blocks.find(mID) == blocks.end())
            return 0;
        int units = 0;
        for (list<pair<int, int>>::iterator block_it: blocks[mID]) {
            units += block_it->second - block_it->first;
            memory.erase(block_it);
        }
        blocks.erase(mID);
        return units;
    }

private:
    int n;
    list<pair<int, int>> memory;
    unordered_map<int, vector<list<pair<int, int>>::iterator>> blocks;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
