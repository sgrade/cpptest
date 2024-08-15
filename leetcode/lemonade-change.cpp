// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter {
            {5, 0},
            {10, 0},
            {20, 0}
        };
        for (int& bill: bills) {
            ++counter[bill];
            if (bill == 20) {
                if (counter[10] > 0) {
                    --counter[10];
                    bill -= 10;
                }
                else {
                    if (counter[5] > 2)
                        counter[5] -= 3;
                    else
                        return false;
                }
            }
            if (bill == 10) {
                if (--counter[5] < 0)
                    return false;
            }
        }
        return true;
    }
};
