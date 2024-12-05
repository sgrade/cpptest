// 2337. Move Pieces to Obtain a String
// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorials Approach 3: Two pointer
class Solution {
public:
    bool canChange(string start, string target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = start.size();
        int idx_s = 0, idx_t = 0;
        while (idx_s < n || idx_t < n) {
            while (idx_s < n && start[idx_s] == '_')
                ++idx_s;
            while (idx_t < n && target[idx_t] == '_')
                ++idx_t;
            if (idx_s == n || idx_t == n)
                return idx_s == n && idx_t == n;

            if (start[idx_s] != target[idx_t] ||
            (start[idx_s] == 'L' && idx_s < idx_t) ||
            (start[idx_s] == 'R' && idx_s > idx_t))
                return false;

            ++idx_s;
            ++idx_t;
        }
        return true;
    }
};
