// 3217. Delete Nodes From Linked List Present in Array
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* pre_ans = new ListNode();
        pre_ans->next = head;
        ListNode* prev = pre_ans;
        while (head) {
            if (st.find(head->val) != st.end()) {
                head = head->next;
                prev->next = head;
            }
            else {
                prev = head;
                head = head->next;
            }
        }
        return pre_ans->next;
    }
};
