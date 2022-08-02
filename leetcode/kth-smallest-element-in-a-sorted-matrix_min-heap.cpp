// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto cmp = [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] > v2[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);
        vector<int> tmp;
        for (int r = 0; r < min(n, k); ++r) {
            tmp = {matrix[r][0], r, 0};
            min_heap.emplace(tmp);
        }
                             
        vector<int> element = min_heap.top();
        
        while (k--) {
            element = min_heap.top();
            int r = element[1];
            int c = element[2];
            if (c < n - 1) {
                tmp = {matrix[r][c + 1], r, c + 1};
                min_heap.emplace(tmp);
            }
            min_heap.pop();
        }
        
        return element[0];
    }
};
