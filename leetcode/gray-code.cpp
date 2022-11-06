// 89. Gray Code
// https://leetcode.com/problems/gray-code/

#include <bits/stdc++.h>

using namespace std;

// Based on Leetcode's Approach 3: Iteration
class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1 << n;
        vector<int> ans(len);
        
        int power_of_two = 1;
        int idx = 1, mask;
        
        while (power_of_two <= n){
            mask = 1 << (power_of_two - 1);
            for (int j = idx - 1; j >= 0; --j) {
                ans[idx++] = mask + ans[j];
            }
            ++power_of_two;
        }
        
        return ans;
    }
};
