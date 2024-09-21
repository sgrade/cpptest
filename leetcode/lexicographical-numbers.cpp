// 386. Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: DFS Approach
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        for (int start = 1; start < 10; ++start)
            dfs(start);
        return ans;
    }

private:
    int n;
    vector<int> ans;
    void dfs (int start) {
        if (start > n)
            return;
        ans.emplace_back(start);
        for (int next_digit = 0; next_digit < 10; ++next_digit) {
            int next_num = start * 10 + next_digit;
            if (next_num > n)
                break;
            dfs(next_num);
        }
    }
};
