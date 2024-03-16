// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's 525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int cnt = 0, ans = 0;
        // <cnt, index>
        unordered_map<int, int> counter;
        counter.emplace(0, -1);
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i] == 0 ? -1 : 1;
            if (counter.find(cnt) != counter.end())
                ans = max(ans, i - counter[cnt]);
            else
                counter[cnt] = i;
        }
        return ans;
    }
};
