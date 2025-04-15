// 2179. Count Good Triplets in an Array
// https://leetcode.com/problems/count-good-triplets-in-an-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Binary Indexed Tree

class FenwickTree {
    public:
        FenwickTree (int n) : tree(n + 1, 0) {}

        void update (int i, int diff) {
            ++i;
            while (i < tree.size()) {
                tree[i] += diff;
                i += i & -i;
            }
        }

        int query (int i) {
            ++i;
            int ans = 0;
            while (i > 0) {
                ans += tree[i];
                i -= i & -i;
            }
            return ans;
        }
    private:
        vector<int> tree;
    };

    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            n = nums1.size();
            vector<int> pos2(n), rev(n);
            for (int i = 0; i < n; ++i)
                pos2[nums2[i]] = i;
            for (int i = 0; i < n; ++i) {
                int num = nums1[i];
                rev[pos2[num]] = i;
            }

            FenwickTree tree(n);
            long long ans = 0;
            for (int v = 0; v < n; ++v) {
                int pos = rev[v];
                int left = tree.query(pos);
                tree.update(pos, 1);
                int right = (n - 1 - pos) - (v - left);
                ans += (long long)left * right;
            }
            return ans;
        }

    private:
        int n;

    };
