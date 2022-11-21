// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        vector<ListNode*> temp;
        ListNode *current = head, *nxt;
        while (current) {
            nxt = current->next;
            current->next = nullptr;
            temp.emplace_back(current);
            current = nxt;
        }
        
        int left = 0, right = temp.size() - 1;
        ListNode *pre_ans = new ListNode(0);
        nxt = pre_ans;
        while (left < right) {
            current = temp[left];
            nxt->next = temp[left];
            nxt = temp[right];
            current->next = nxt;
            ++left;
            --right;
        }
        if (left == right) {
            nxt->next = temp[left];
        }
        
        head = pre_ans->next;
        return;
    }
};
