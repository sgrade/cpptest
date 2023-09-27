// 1399. Count Largest Group
// https://leetcode.com/problems/count-largest-group/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> counter(37);
        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i, rem; 
            while (x != 0) {
                rem = x % 10;
                sum += rem;
                x /= 10;
            }
            ++counter[sum];
        }
        sort(counter.begin(), counter.end(), greater<int>());
        int ans = 1, i = 1;
        while (counter[i++] == counter[0])
            ++ans;
        return ans;
    }
};
