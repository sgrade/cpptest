// 1239. Maximum Length of a Concatenated String with Unique Characters
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i)
            ans = max(ans, dfs(i, vector<bool>(26), arr));
        return ans;
    }
private:
    int dfs(int idx, vector<bool> current, vector<string>& arr) {
        bool duplicate_found = false;
        for (const char& ch: arr[idx]) {
            int idx = ch - 'a';
            if (current[idx]) {
                duplicate_found = true;
                break;
            }
            else
                current[idx] = true;
        }
        if (duplicate_found)
            return 0;
        int ans = count(current.begin(), current.end(), true);
        for (int i = idx + 1; i < arr.size(); ++i)
            ans = max(ans, dfs(i, current, arr));
        return ans;
    }
};
