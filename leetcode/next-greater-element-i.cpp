// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Using Stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for (const int& el: nums2) {
            while (!st.empty() && el > st.top()) {
                mp[st.top()] = el;
                st.pop();
            }
            st.emplace(el);
        }
        while (!st.empty()) {
            mp.emplace(st.top(), -1);
            st.pop();
        }
        for (int& el: nums1)
            el = mp[el];
        return nums1;
    }
};
