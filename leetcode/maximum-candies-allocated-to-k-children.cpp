// 2226. Maximum Candies Allocated to K Children
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's solution
class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            this->k = k;
            int left = 0, right = *max_element(candies.begin(), candies.end());
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (canAllocate(candies, mid))
                    left = mid;
                else
                    right = mid - 1;
            }
            return left;
        }

    private:
        long long k;
        bool canAllocate(vector<int>& candies, int x) {
            long long children = 0;
            for (int i = 0; i < candies.size(); ++i)
                children += candies[i] / x;
            return children >= k;
        }
    };
