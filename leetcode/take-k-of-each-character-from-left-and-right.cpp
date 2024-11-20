// Approach 2: Sliding Window
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Sliding Window
class Solution {
public:
    int takeCharacters(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        vector<int> counter(3);
        for (int i = 0; i < n; ++i) {
            int char_idx = s[i] - 'a';
            ++counter[char_idx];
        }
        for (const int& cnt: counter) {
            if (cnt < k)
                return -1;
        }

        int left = 0, max_excluded = 0;
        vector<int> current(3);
        for (int right = 0; right < n; ++right) {
            int idx_right = s[right] - 'a';
            ++current[idx_right];
            while (left <= right && (counter[0] - current[0] < k || counter[1] - current[1] < k || counter[2] - current[2] < k)) {
                int idx_left = s[left] - 'a';
                --current[idx_left];
                ++left;
            }
            max_excluded = max(max_excluded, right - left + 1);
        }
        return n - max_excluded;
    }
};
