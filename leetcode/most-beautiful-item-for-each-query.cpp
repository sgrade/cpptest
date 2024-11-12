// 2070. Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Sorting Items + Binary Search
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(items.begin(), items.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[0] < v2[0];
        });

        int mx = items[0][1];
        for (vector<int>& item: items) {
            mx = max(mx, item[1]);
            item[1] = mx;
        }

        for (int& q: queries) {
            auto it = upper_bound(items.begin(), items.end(), q, [](int value, const vector<int>& v){
                return value < v[0];
            });
            if (it == items.begin())
                q = 0;
            else {
                --it;
                q = (*it)[1];
            }
        }
        return queries;
    }
};
