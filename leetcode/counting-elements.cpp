// 1426. Counting Elements
// https://leetcode.com/problems/counting-elements/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (const int& num: arr)
            ++counter[num];
        int ans = 0;
        for (auto& [num, cnt]: counter) {
            if (counter.find(num + 1) != counter.end())
                ans += cnt;
        }
        return ans;
    }
};
