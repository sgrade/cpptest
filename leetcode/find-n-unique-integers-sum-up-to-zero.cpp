// 1304. Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

#include <vector>

using std::vector;


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        if (n == 1) {
            return ans;
        }
        ans[0] = 1;
        for (int i = 1; i < n / 2; ++i) {
            ans[i] = ans[i - 1] + 1;
        }
        for (int i = n / 2; i < n / 2 * 2; ++i) {
            ans[i] = -ans[i - n / 2];
        }
        return ans;
    }
};
