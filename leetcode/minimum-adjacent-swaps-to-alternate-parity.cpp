// 3587. Minimum Adjacent Swaps to Alternate Parity
// https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/solutions/6869432/easiest-code-with-example-walkthrough
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0)
                even.emplace_back(i);
            else
                odd.emplace_back(i);
        }
        int e = even.size(), o = odd.size();
        if (abs(e - o) > 1)
            return -1;
        bool pick_even = e > o ? true : false;
        
        int ans = numeric_limits<int>::max();
        if (e >= o)
            ans = calculate(even);
        if (o >= e)
            ans = min(ans, calculate(odd));

        return ans;
    }

private:
    int calculate(vector<int> indexes) {
        int ans = 0;
        for (int i = 0; i < indexes.size(); ++i)
            ans += abs(indexes[i] - 2 * i);
        return ans;
    }
};
