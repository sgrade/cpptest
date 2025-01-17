// 2683. Neighboring Bitwise XOR
// https://leetcode.com/problems/neighboring-bitwise-xor/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Cumulative XOR
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int x = 0;
        for (const int& y: derived)
            x ^= y;
        return x == 0;
    }
};
