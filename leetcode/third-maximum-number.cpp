// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (const int& el: nums) {
            st.emplace(el);
        }
        if (st.size() < 3) {
            return *st.rbegin();
        }
        set<int>::reverse_iterator rit = st.rbegin();
        ++rit;
        ++rit;
        return *rit;
    }
};
