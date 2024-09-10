// 2807. Insert Greatest Common Divisors in Linked List
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* pre_head = new ListNode;
        pre_head->next = head;
        while (head->next) {
            ListNode* mid = new ListNode;
            mid->val = gcd(head->val, head->next->val);
            mid->next = head->next;
            head->next = mid;
            head = mid->next;
        }
        return pre_head->next;
    }
};
