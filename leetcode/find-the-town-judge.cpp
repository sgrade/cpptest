// 997. Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> idx_trusts(n + 1), idx_is_trusted(n + 1);
        for (const vector<int>& e: trust) {
            ++idx_trusts[e[0]];
            ++idx_is_trusted[e[1]];
        }
        for (int i = 1; i < n + 1; ++i) {
            if (idx_trusts[i] == 0 && idx_is_trusted[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
