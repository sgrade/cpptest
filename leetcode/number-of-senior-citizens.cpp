// 2678. Number of Senior Citizens
// https://leetcode.com/problems/number-of-senior-citizens/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (const string& s: details) {
            int age = stoi(s.substr(11, 2));
            if (age > 60)
                ++ans;
        }
        return ans;
    }
};
