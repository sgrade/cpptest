// 2206. Divide Array Into Equal Pairs
// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_set<int> seen;
            for (const int& num: nums) {
                if (seen.find(num) == seen.end())
                    seen.emplace(num);
                else
                    seen.erase(num);
            }
            return seen.size() == 0;
        }
    };
