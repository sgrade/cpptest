// 2138. Divide a String Into Groups of Size k
// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (size_t i = 0; i < s.size(); i += k)
            ans.emplace_back(s.substr(i, k));
        while (ans.back().size() < k)
            ans.back() += fill;
        return ans;
    }
};
