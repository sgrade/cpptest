// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Using Heap
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>> > min_heap;
        min_heap.emplace(nums1[0] + nums2[0], pair<int, int>(0, 0));

        vector<vector<int>> ans;
        
        set<pair<int, int>> visited;
        visited.emplace(0, 0);
        int idx1, idx2, n1 = nums1.size(), n2 = nums2.size();

        while (k-- && !min_heap.empty()) {
            auto [_, i] = min_heap.top();
            min_heap.pop();
            idx1 = i.first;
            idx2 = i.second;

            ans.emplace_back(vector<int>{nums1[idx1], nums2[idx2]});
            
            if (idx1 + 1 < n1 && visited.find({idx1 + 1, idx2}) == visited.end()) {
                min_heap.emplace(nums1[idx1 + 1] + nums2[idx2], pair<int, int>{idx1 + 1, idx2});
                visited.insert({idx1 + 1, idx2});
            }
            if (idx2 + 1 < n2 && visited.find({idx1, idx2 + 1}) == visited.end()) {
                min_heap.emplace(nums1[idx1] + nums2[idx2 + 1], pair<int, int>{idx1, idx2 + 1});
                visited.insert({idx1, idx2 + 1});
            }
        }
       
        return ans;
    }
};
