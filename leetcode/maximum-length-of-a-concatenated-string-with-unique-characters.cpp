// 1239. Maximum Length of a Concatenated String with Unique Characters
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<vector<bool>> seen(1, vector<bool>(26));
        int ans = 0;
        for (const string& s: arr) {
            for (int i = 0; i < seen.size(); ++i) {
                vector<bool> current = seen[i];
                bool duplicate_found = false;
                for (const char& ch: s) {
                    int idx = ch - 'a';
                    if (current[idx]) {
                        duplicate_found = true;
                        break;
                    }
                    else
                        current[idx] = true;
                }
                if (duplicate_found)
                    continue;
                seen.emplace_back(current);
                int current_ans = count(current.begin(), current.end(), true);
                ans = max(ans, current_ans);
            }
        }
        return ans;
    }
};
