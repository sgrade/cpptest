// 1980. Find Unique Binary String
// https://leetcode.com/problems/find-unique-binary-string/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Cantor's Diagonal Argument
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        char ch;
        for (int i = 0; i < nums.size(); ++i) {
            ch = nums[i][i];
            ans += ch == '0' ? '1' : '0';
        }
        return ans;
    }
};
