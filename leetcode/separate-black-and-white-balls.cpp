// 2938. Separate Black and White Balls
// https://leetcode.com/problems/separate-black-and-white-balls/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans = 0;
        int zeroes = count(s.begin(), s.end(), '0');
        size_t zero = 0, one = 0;
        while (true) {
            zero = s.find('0', zero);
            if (zero == string::npos)
                break;
            one = s.find('1', one);
            if (one == string::npos)
                break;
            if (one < zero) {
                ans += zero - one;
                swap(s[one], s[zero]);
                ++one;
                ++zero;
            }
            else {
                ++zero;
            }
        }
        return ans;
    }
};
