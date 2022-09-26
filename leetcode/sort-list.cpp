// 148. Sort List
// https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        multimap<int, ListNode*> pointers;
        ListNode* current = head;
        ListNode* nxt;
        while (current) {
            nxt = current->next;
            current->next = nullptr;
            pointers.emplace(current->val, current);
            current = nxt;
        }
        ListNode* pre_head = new ListNode;
        current = pre_head;
        for (auto &[val, node]: pointers) {
            current->next = node;
            current = node;
        }
        return pre_head -> next;
    }
};
