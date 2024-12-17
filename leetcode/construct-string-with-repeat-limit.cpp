// 2182. Construct String With Repeat Limit
// https://leetcode.com/problems/construct-string-with-repeat-limit/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach 2: Heap-Optimized Greedy Character Frequency Distribution
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (counter[i] == 0)
                continue;
            pq.emplace(i);
        }

        string ans;
        while (!pq.empty()) {
            int idx = pq.top(), cnt = counter[idx];
            pq.pop();
            int mn = min(cnt, repeatLimit);
            counter[idx] -= mn;
            char ch = 'a' + idx;
            ans.append(mn, ch);

            if (counter[idx] > 0 && !pq.empty()) {
                int idx2 = pq.top(), cnt2 = counter[idx2];
                pq.pop();
                char ch2 = 'a' + idx2;
                ans += ch2;
                --counter[idx2];
                if (counter[idx2] > 0)
                    pq.emplace(idx2);
                pq.emplace(idx);
            }
        }

        return ans;
    }
};
