// 2244. Minimum Rounds to Complete All Tasks
// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counter;
        for (const int& difficulty: tasks) {
            ++counter[difficulty];
        }
        int ans = 0, rem;
        for (auto &p: counter) {
            if (p.second == 1) {
                return -1;
            }
            ans += (p.second) / 3 + (p.second % 3 > 0);
        }
        return ans;
    }
};