// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> seen(26, -1);
        int ans = 1e5 + 1;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (seen[idx] != -1)
                seen[idx] = 1e5 + 1;
            else
                seen[idx] = i;
        }
        sort(seen.begin(), seen.end());
        for (const int& i: seen)
            if (i != -1 && i != 1e5 + 1)
                return i;
        return -1;
    }
};
