// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;


// There are much shorter solutions in the Discussions
// https://leetcode.com/problems/top-k-frequent-elements/discuss/2182665/C%2B%2B-70-solution-without-heaps
// https://leetcode.com/problems/top-k-frequent-elements/discuss/2182321/Easy-understanding-with-comments-or-C%2B%2B


class Solution {
private:
    vector<int>uniq;
    map<int, int> cnt;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
        }
        
        int n = cnt.size();
        for (const auto &[key, value]: cnt) {
            uniq.push_back(key);
        }
        
        // From the leetcode's solution:
        // kth top frequent element is (n - k)th less frequent.
        // Do a partial sort: from less frequent to the most frequent, till
        // (n - k)th less frequent element takes its place (n - k) in a sorted array.
        // All element on the left are less frequent.
        // All the elements on the right are more frequent.
        quickselect(0, n - 1, n - k);
        vector<int> ans(k);
        copy(uniq.begin() + n - k, uniq.end(), ans.begin());
        return ans;
    }
    
    void quickselect(int left, int right, int k_smallest) {
        if (left == right) return;
        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(left, right, pivot_index);
        if (k_smallest == pivot_index) {
            return;
        }
        else if (k_smallest < pivot_index) {
            quickselect(left, pivot_index - 1, k_smallest);
        }
        else {
            quickselect(pivot_index + 1, right, k_smallest);
        }
    }
    
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = cnt[uniq[pivot_index]];
        swap(uniq[pivot_index], uniq[right]);
        int store_index = left;
        for (int i = left; i <= right; ++i) {
            if (cnt[uniq[i]] < pivot_frequency) {
                swap(uniq[store_index], uniq[i]);
                store_index += 1;
            }
        }
        swap (uniq[right], uniq[store_index]);
        return store_index;
    }
};
