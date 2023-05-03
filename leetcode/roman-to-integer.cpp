// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Right-to-Left Pass
class Solution {
public:
    int romanToInt(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            current = chars[s[i]];
            if (current < prev)
                ans -= current;
            else 
                ans += current;
            prev = current;
        }
        return ans;
    }

private:
    int current, prev = 0;
    unordered_map<char, int> chars {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
};
