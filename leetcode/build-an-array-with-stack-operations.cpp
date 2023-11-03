// 1441. Build an Array With Stack Operations
// https://leetcode.com/problems/build-an-array-with-stack-operations/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Simulate
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        for (const int& x: target) {
            while (i < x - 1) {
                ans.emplace_back("Push");
                ans.emplace_back("Pop");
                ++i;
            }
            ans.emplace_back("Push");
            ++i;
        }
        return ans;
    }
private:
    stack<int> st;
};
