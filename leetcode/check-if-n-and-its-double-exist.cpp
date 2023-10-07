// 1346. Check If N and Its Double Exist
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> cntr;
        for (const int& el: arr)
            ++cntr[el];
        for (auto& [num, cnt]: cntr) {
            if ((cntr.find(num << 1) != cntr.end() && num != 0) || (num == 0 && cnt > 1))
                return true;
        }
        return false;
    }
};
