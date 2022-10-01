// 179. Largest Number
// https://leetcode.com/problems/largest-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string ans, s;
        for (const int &num: nums) {
            s = to_string(num);
            temp.emplace_back(s);
        }
        sort(temp.begin(), temp.end(), [](const string &s1, const string &s2){
            return (s1 + s2 > s2 + s1);
        });
        if (temp[0] == "0") {
            return "0";
        }
        for (const string &s: temp) {
            ans += s;
        }
        return ans;
    }
};
