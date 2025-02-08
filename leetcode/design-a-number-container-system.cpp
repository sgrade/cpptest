// 2349. Design a Number Container System
// https://leetcode.com/problems/design-a-number-container-system/

#include <bits/stdc++.h>

using namespace std;


class NumberContainers {
public:
    NumberContainers() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    void change(int index, int number) {
        if (idx_to_num.find(index) != idx_to_num.end()) {
            int num = idx_to_num[index];
            if (num_to_idx[num].size() == 1)
                num_to_idx.erase(num);
            else
                num_to_idx[num].erase(index);
        }
        num_to_idx[number].emplace(index);
        idx_to_num[index] = number;
    }
    
    int find(int number) {
        if (num_to_idx.find(number) == num_to_idx.end())
            return -1;
        return *num_to_idx[number].begin();
    }

private:
    unordered_map<int, set<int>> num_to_idx;
    unordered_map<int, int> idx_to_num;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
