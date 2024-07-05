// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> ans{numeric_limits<int>::max(), -1};
        if (!head->next->next)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* nxt = head->next->next;
        int min_idx = -1, max_idx = -1, cur_idx = 1;
        while (nxt) {
            if ((cur->val > prev->val && cur->val > nxt->val) || (cur->val < prev->val && cur->val < nxt->val)) {
                if (min_idx == -1)
                    min_idx = cur_idx;
                else
                    ans[1] = cur_idx - min_idx;
                if (max_idx != -1)
                    ans[0] = min(ans[0], cur_idx - max_idx);
                max_idx = cur_idx;
            }
            ++cur_idx;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        if (ans[0] == numeric_limits<int>::max())
            ans[0] = -1;
        return ans;
    }
};
