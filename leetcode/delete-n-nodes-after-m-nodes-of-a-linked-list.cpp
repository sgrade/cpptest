// 1474. Delete N Nodes After M Nodes of a Linked List
// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/

#include <bits/stdc++.h>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* cur = head;
        ListNode* nxt = head->next;
        while (nxt) {
            int keep = m, remove = n;
            while (nxt && --keep) {
                cur = nxt;
                nxt = cur->next;
            }
            while (nxt && remove--) {
                nxt = nxt->next;
            }
            if (!nxt)
                cur->next = nullptr;
            else {
                cur->next = nxt;
                cur = nxt;
                nxt = cur->next;
            }
        }
        return head;
    }
};
