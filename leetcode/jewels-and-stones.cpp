// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jls;
        for (const char& ch: jewels)
            jls.emplace(ch);
        int ans = 0;
        for (const char& ch: stones) {
            if (jls.find(ch) != jls.end())
                ++ans;
        }
        return ans;
    }
};
