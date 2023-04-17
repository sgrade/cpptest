// 1570. Dot Product of Two Sparse Vectors
// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

#include <bits/stdc++.h>

using namespace std;


class SparseVector {
public:
    vector<int> nums;
    SparseVector(vector<int> &nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        this->nums = nums;
        n = nums.size();
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums[i] * vec.nums[i];
        }
        return ans;
    }

private:
    int n;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
