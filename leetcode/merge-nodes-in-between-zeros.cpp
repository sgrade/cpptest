// 2181. Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* pre_ans = new ListNode();
        ListNode* current_ans = pre_ans;
        ListNode* prev = head;
        ListNode* nxt = head->next;
        int sum = 0;
        while (nxt) {
            if (nxt->val != 0) {
                sum += nxt->val;
                nxt = nxt->next;
                continue;
            }
            ListNode* node = new ListNode(sum);
            current_ans->next = node;
            current_ans = node;
            nxt = nxt->next;
            sum = 0;
        }
        return pre_ans->next;
    }
};
