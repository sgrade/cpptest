// 1865. Finding Pairs With a Certain Sum
// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

#include <bits/stdc++.h>

using namespace std;


class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (const int& num: nums2)
            ++counter[num];
    }
    
    void add(int index, int val) {
        --counter[nums2[index]];
        nums2[index] += val;
        ++counter[nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (const int& num1: nums1) {
            int num2 = tot - num1;
            if (counter.find(num2) != counter.end())
                ans += counter[num2];
        }
        return ans;
    }

private:
    vector<int> nums1, nums2;
    unordered_map<int, int> counter;
    int min_num2 = 0;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
