// 3005. Count Elements With Maximum Frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (const int& num: nums)
            ++counter[num];
        int max_freq = 0;
        for (const auto& [_, freq]: counter)
            max_freq = max(max_freq, freq);
        int ans = 0;
        for (const auto& [_, freq]: counter) {
            if (freq == max_freq)
                ++ans;
        }
        return ans * max_freq;
    }
};
