// 3479. Fruits Into Baskets III
// https://leetcode.com/problems/fruits-into-baskets-iii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Segment Tree + Binary Search
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        if (n == 0) {
            return fruits.size();
        }

        this->baskets = baskets;

        int ans = 0;
        segment_tree.resize(400007);
        buildSegTree(1, 0, n - 1);

        for (int i = 0; i < fruits.size(); ++i) {
            int l = 0, r = n - 1, cur_ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int max_val = query(1, 0, n - 1, 0, mid);
                if (max_val >= fruits[i]) {
                    cur_ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (cur_ans != -1 && this->baskets[cur_ans] >= fruits[i]) {
                updateSegTree(1, 0, n - 1, cur_ans, numeric_limits<int>::min());
                this->baskets[cur_ans] = numeric_limits<int>::min();
            } else {
                ++ans;
            }
        }
        return ans;
    }

private:
    vector<int> segment_tree;
    vector<int> baskets;

    void buildSegTree(int p, int l, int r) {
        if (l == r) {
            segment_tree[p] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSegTree(2 * p, l, mid);
        buildSegTree(2 * p + 1, mid + 1, r);
        segment_tree[p] = max(segment_tree[2 * p], segment_tree[2 * p + 1]);
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return numeric_limits<int>::min();
        }
        if (ql <= l && r <= qr) {
            return segment_tree[p];
        }
        int mid = (l + r) / 2;
        return max(query(2 * p, l, mid, ql, qr),
                   query(2 * p + 1, mid + 1, r, ql, qr));
    }

    void updateSegTree(int p, int l, int r, int pos, int val) {
        if (l == r) {
            segment_tree[p] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            updateSegTree(2 * p, l, mid, pos, val);
        else
            updateSegTree(2 * p + 1, mid + 1, r, pos, val);
        segment_tree[p] = max(segment_tree[2 * p], segment_tree[2 * p + 1]);
    }
};
