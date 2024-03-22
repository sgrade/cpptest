// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (head->next == nullptr)
            return true;
        int len = 0;
        ListNode* node = head;
        while(node) {
            ++len;
            node = node->next;
        }

        // Reverse the first half
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt;
        for (int i = 0; i < len / 2; ++i) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        if (len % 2 == 1)
            cur = cur->next;

        while (cur) {
            if (cur->val != prev->val)
                return false;
            cur = cur->next;
            prev = prev->next;
        }

        return true;
    }
};
