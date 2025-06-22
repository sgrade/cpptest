// 683. K Empty Slots
// https://leetcode.com/problems/k-empty-slots/

#include <bits/stdc++.h>

using namespace std;


// Used https://leetcode.com/problems/k-empty-slots/solutions/4861758/insert-into-sorted-set-data-structure-c
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        set<int> active;
        for (int i = 0; i < bulbs.size(); ++i) {
            int pos = bulbs[i];
            auto it = active.emplace(pos).first;
            if (it != active.begin()) {
                int prev_pos = *prev(it);
                if (pos - prev_pos == k + 1)
                    return i + 1;
            }
            if (it != active.end()) {
                int next_pos = *next(it);
                if (next_pos - pos == k + 1 )
                    return i + 1;
            }
        }
        return -1;
    }
};
