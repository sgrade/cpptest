// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode();
        ListNode* curNode = head;
        
        int cur = 0;
        while(l1 || l2 || cur) {
            
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }
            
            curNode->next = new ListNode();
            curNode = curNode->next;
            
            curNode->val = cur % 10;
            cur /= 10;
        }
        
        return head->next;
    }
};
