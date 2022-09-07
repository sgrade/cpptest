// 70. Two Sum III - Data structure design
// https://leetcode.com/problems/two-sum-iii-data-structure-design/

#include <bits/stdc++.h>

using namespace std;

class TwoSum {
public:
    unordered_map<long, int> counter;
    TwoSum() = default;
    
    void add(int number) {
        ++counter[number];
    }
    
    bool find(int value) {
        long x;
        for (auto &[number, count]: counter) {
            x = value - number;
            if (counter.find(x) != counter.end() && (number != x || counter[x] > 1)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
