// 3217. Delete Nodes From Linked List Present in Array
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(nums.begin(), nums.end());
    ListNode* pre_head = new ListNode(0, head);
    ListNode* prev = pre_head;
    while (prev->next) {
      if (st.count(prev->next->val)) {
        prev->next = prev->next->next;
      } else {
        prev = prev->next;
      }
    }
    return pre_head->next;
  }
};
