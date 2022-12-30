// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

#include <bits/stdc++.h>

using namespace std;


// Key ideas are from https://leetcode.com/problems/ugly-number-ii/solutions/69364/my-16ms-c-dp-solution-with-short-explanation/
class Solution {
public:
    int nthUglyNumber(int n) {
        int t2 = 0, t3 = 0, t5 = 0;
        int t2_by_2, t3_by_3, t5_by_5;
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            t2_by_2 = ans[t2] * 2;
            t3_by_3 = ans[t3] * 3;
            t5_by_5 = ans[t5] * 5;
            ans[i] = min({t2_by_2, t3_by_3, t5_by_5});
            if (ans[i] == t2_by_2) {
                ++t2;
            }
            if (ans[i] == t3_by_3) {
                ++t3;
            }
            if (ans[i] == t5_by_5) {
                ++t5;
            }
        }
        return ans.back();
    }
};
