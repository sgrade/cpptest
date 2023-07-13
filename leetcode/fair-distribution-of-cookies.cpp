// 2305. Fair Distribution of Cookies
// https://leetcode.com/problems/fair-distribution-of-cookies/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Backtracking
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans;
        n = cookies.size();
        vector<int> distribution(k);
        return  distribute(distribution, 0, cookies, k, k);
    }

private:
    int n;
    int distribute (vector<int> distribution, int i, vector<int>& cookies, int& k, int zero_count) {
        if (n - i < zero_count)
            return numeric_limits<int>::max();
        
        if (i == n)
            return *max_element(distribution.begin(), distribution.end());
        
        int ans = numeric_limits<int>::max();
        for (int j = 0; j < k; ++j) {
            zero_count -= distribution[j] == 0 ? 1 : 0;
            distribution[j] += cookies[i];
            ans = min(ans, distribute(distribution, i + 1, cookies, k, zero_count));
            distribution[j] -= cookies[i];
            zero_count += distribution[j] == 0 ? 1 : 0;
        }

        return ans;
    }
};
