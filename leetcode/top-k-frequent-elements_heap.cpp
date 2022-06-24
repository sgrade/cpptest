// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;
        
        map<int, int> counter;
        for (int i = 0; i < nums.size(); ++i) {
            ++counter[nums[i]];
        }
        
        auto comp = [&counter](int x, int y) {
            return counter[x] > counter[y];
        };
        priority_queue<int, vector<int>, decltype(comp)> best_k(comp);
        
        for (const auto &[key, value]: counter) {
            best_k.push(key);
            if (best_k.size() > k) {
                best_k.pop();
            }
        }
        
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = best_k.top();
            best_k.pop();
        }
        
        return ans;
    }
};
