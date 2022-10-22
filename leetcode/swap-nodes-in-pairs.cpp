// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode;
        ListNode* ans = pre;
        pre->next = head;
        ListNode* current = head;
        ListNode* nxt;
        while (current && current->next) {
            if (current->next->next) {
                nxt = current->next->next;
            }
            else {
                nxt = nullptr;
            }
            pre->next = current->next;
            pre->next->next = current;
            
            current->next = nxt;
            pre = current;
            
            current = nxt;
        }
        
        return ans->next;
    }
};
