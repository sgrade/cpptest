// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int &el: nums) {
            st.emplace(el);
        }
        
        int ans = 0;
        
        for (const int &el: st) {
            if (st.find(el - 1) == st.end()) {
                int current_ans = 1;
                int current_num = el;
                
                while (st.find(current_num + 1) != st.end()) {
                    ++current_ans;
                    ++current_num;
                }
                
                ans = max(ans, current_ans);
            }
        }
        
        return ans;
    }
};
