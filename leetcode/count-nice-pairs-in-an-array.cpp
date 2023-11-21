// 1814. Count Nice Pairs in an Array
// https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        for (int& num: nums)
            num -= rev(num);

        int ans = 0;
        int MOD = 1e9 + 7;
        unordered_map<int, int> counter;
        for (const int& num: nums) {
            ans = (ans + counter[num]) % MOD;
            ++counter[num];
        }
        return ans;
    }
private:
    int rev(int num) {
        int x = 0;
        while (num) {
            x *= 10;
            x += num % 10;
            num /= 10;
        }
        return x;
    }
};
