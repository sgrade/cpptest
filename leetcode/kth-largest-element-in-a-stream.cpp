// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>

using namespace std;


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const int& num: nums) {
            pq.emplace(num);
            if (pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        if (pq.size() < k)
            pq.emplace(val);
        else if (val > pq.top()) {
            pq.emplace(val);
            pq.pop();
        }
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
