// 2999. Count the Number of Powerful Integers
// https://leetcode.com/problems/count-the-number-of-powerful-integers/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            string left = to_string(start - 1), right = to_string(finish);
            return calculate(right, s, limit) - calculate(left, s, limit);
        }

    private:
        long long calculate(string x, string s, int limit) {
            if (x.size() < s.size())
                return 0;
            if (x.size() == s.size())
                return x >= s ? 1 : 0;

            int prefix_len = x.size() - s.size();
            string suffix = x.substr(prefix_len, s.size());
            long long ans = 0;
            for (int i = 0; i < prefix_len; ++i) {
                if (limit < (x[i] - '0')) {
                    ans += (long)pow(limit + 1, prefix_len - i);
                    return ans;
                }
                ans += (long)(x[i] - '0') * (long)pow(limit + 1, prefix_len - i - 1);
            }

            if (suffix >= s)
                ++ans;
            return ans;
        }
    };
