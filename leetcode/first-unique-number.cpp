// 1429. First Unique Number
// https://leetcode.com/problems/first-unique-number/

#include <bits/stdc++.h>

using namespace std;


class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (const int& num: nums)
            ++all[num].first;
        for (const int& num: nums) {
            int& cnt = all[num].first;
            if (cnt == 1) {
                auto it = uniq.insert(uniq.end(), num);
                all[num].second = it;
            }
        }
    }
    
    int showFirstUnique() {
        if (uniq.empty())
            return -1;
        return uniq.front();
    }
    
    void add(int value) {
        if (all.find(value) == all.end()) {
            auto it = uniq.insert(uniq.end(), value);
            all[value] = pair<int, list<int>::iterator>(1, it);
        }
        else {
            int& cnt = all[value].first;
            if (cnt == 1)
                uniq.erase(all[value].second);
            ++all[value].first;
        }
    }

private:
    list<int> uniq;
    map<int, pair<int, list<int>::iterator>> all;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */