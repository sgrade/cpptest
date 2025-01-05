// 2381. Shifting Letters II
// https://leetcode.com/problems/shifting-letters-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Difference Array
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = s.size();
        diffs.resize(n);
        for (vector<int>& shift: shifts) {
            int start = shift[0], end = shift[1], dir = shift[2];
            if (dir == 1) {
                ++diffs[start];
                if (end + 1 < n)
                    --diffs[end + 1];
            }
            else {
                --diffs[start];
                if (end + 1 < n)
                    ++diffs[end + 1];
            }
        }

        string ans(n, ' ');
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt = (cnt + diffs[i]) % 26;
            if (cnt < 0)
                cnt += 26;
            ans[i] = 'a' + (s[i] - 'a' + cnt) % 26;
        }
        return ans;
    }

private:
    int n;
    vector<int> diffs;
};
