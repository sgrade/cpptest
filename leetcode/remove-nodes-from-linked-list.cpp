// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/

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
    ListNode* removeNodes(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // <val, index>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> to_remove;

        ListNode* node = head;
        int i = 0;
        while (node) {
            while (!pq.empty() && pq.top().first < node->val) {
                to_remove.emplace(pq.top().second);
                pq.pop();
            }
            pq.emplace(node->val, i++);
            node = node->next;
        }

        i = 0;
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        node = pre_head;
        set<int>::iterator it = to_remove.begin();
        while (it != to_remove.end()) {
            int current_idx = *it;
            if (i == current_idx) {
                if (node->next->next)
                    node->next = node->next->next;
                ++it;
            }
            else
                node = node->next;
            ++i;
        }

        return pre_head->next;
    }
};
