// 2816. Double a Number Represented as a Linked List
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

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
    ListNode* doubleIt(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* node = head;
        vector<int> digits(1);
        while(node) {
            digits.emplace_back(node->val);
            node = node->next;
        }

        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] = digits[i] * 2 + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }

        node = head;
        if (digits[0] != 0) {
            ListNode* new_head = new ListNode(digits[0]);
            new_head->next = head;
            head = new_head;
        }
        for (int i = 1; i < digits.size(); ++i) {
            node->val = digits[i];
            node = node->next;
        }

        return head;
    }
};
