// 1624. Largest Substring Between Two Equal Characters
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> idxs(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (idxs[idx] != -1)
                ans = max(ans, i - idxs[idx] - 1);
            else
                idxs[idx] = i;
        }
        return ans;
    }
};
