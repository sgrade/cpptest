// 2502. Design Memory Allocator
// https://leetcode.com/problems/design-memory-allocator/

#include <bits/stdc++.h>

using namespace std;


class Allocator {
public:
    Allocator(int n) {
        this->n = n;
        memory.resize(n);
    }
    
    int allocate(int size, int mID) {
        int left = 0;
        while (left < n) {
            int cnt = 0;
            int i = left;
            for (; i < n; ++i) {
                if (memory[i] == 0)
                    ++cnt;
                else
                    break;
            }
            if (cnt >= size) {
                fill(memory.begin() + left, memory.begin() + left + size, mID);
                blocks[mID].emplace_back(left, left + size);
                return left;
            }
            left = i + 1;
        }
        return -1;
    }
    
    int free(int mID) {
        if (blocks.find(mID) == blocks.end())
            return 0;
        int units = 0;
        for (const auto& [left, right]: blocks[mID]) {
            fill(memory.begin() + left, memory.begin() + right, 0);
            units += right - left;
        }
        blocks.erase(mID);
        return units;
    }

private:
    int n;
    vector<int> memory;
    unordered_map<int, vector<pair<int, int>>> blocks;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
