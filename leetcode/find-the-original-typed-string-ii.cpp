// 3333. Find the Original Typed String II
// https://leetcode.com/problems/find-the-original-typed-string-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming + Prefix Sum Optimization
class Solution {
public:
    int possibleStringCount(string word, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = word.size(), chars = 1;
        vector<int> freq;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1])
                ++chars;
            else {
                freq.emplace_back(chars);
                chars = 1;
            }
        }
        freq.emplace_back(chars);

        int ans = 1;
        for (const int f: freq)
            ans = 1LL * ans * f % MOD;

        if (freq.size() >= k)
            return ans;

        vector<int> f(k), g(k, 1);
        f[0] = 1;
        for (int i = 0; i < freq.size(); ++i) {
            vector<int> cur_f(k);
            for (int j = 1; j < k; ++j) {
                cur_f[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0)
                    cur_f[j] = (cur_f[j] - g[j - freq[i] - 1] + MOD) % MOD;
            }
            vector<int> cur_g(k);
            cur_g[0] = cur_f[0];
            for (int j = 1; j < k; ++j)
                cur_g[j] = (cur_g[j - 1] + cur_f[j]) % MOD;
            f = cur_f;
            g = cur_g;
        }

        ans = (ans - g[k - 1] + MOD) % MOD;
        return ans;
    }

private:
    const int MOD = 1e9 + 7;
};
