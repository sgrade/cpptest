// 179. Largest Number
// https://leetcode.com/problems/largest-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<string> strings(n);
        for (int i = 0; i < n; ++i)
            strings[i] = to_string(nums[i]);
        // Used ides from the editorial's overview
        sort (strings.begin(), strings.end(), [](const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        });
        if (strings[0] == "0")
            return "0";
        string ans;
        for (const string& s: strings)
            ans += s;
        return ans;
    }
};
