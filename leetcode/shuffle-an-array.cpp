// 384. Shuffle an Array
// https://leetcode.com/problems/shuffle-an-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach #2 Fisher-Yates Algorithm

class Solution {
public:
    Solution(vector<int>& nums) {
        srand (time(NULL));
        original = nums;
        v = nums;
    }
    
    vector<int> reset() {
        v = original;
        return original;
    }
    
    vector<int> shuffle() {
        int j;
        for (int i = 0; i < v.size(); ++i) {
            j = RandRange(i, v.size());
            swap(v[i], v[j]);
        }
        return v;
    }

private:
    vector<int> v;
    vector<int> original;
    
    int RandRange(const int &mn, const int &mx) {
        return rand() % (mx - mn) + mn;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
