// 1191. K-Concatenation Maximum Sum
// https://leetcode.com/problems/k-concatenation-maximum-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/k-concatenation-maximum-sum/solutions/382885/short-and-concise-o-n-c-solution/
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size(), ans = arr[0], current_ans = arr[0];
        long long total = accumulate(arr.begin(), arr.end(), 0);
        long long mod = 1e9 + 7;
        // we only need to consider k == 1 and k == 2
        for (int i = 1; i < n * min(k, 2); ++i) {
            current_ans = max(arr[i % n], current_ans + arr[i % n]);
            ans = max(ans, current_ans);
        }
        return max<long long>({0, ans, total * k}) % mod;
    }
};
