// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* pre = new ListNode;
        pre->next = head;
        
        ListNode* last_uniq_node = pre;
        ListNode* candidate;
        int cnt = 1;
        
        while (head) {
            candidate = head;
            cnt = 1;
            
            while (head->next && head->val == head->next->val) {
                head = head->next;
                ++cnt;
            }         
            
            if (cnt == 1) {
                last_uniq_node->next = candidate;
                last_uniq_node = candidate;
            }
            
            head = head->next;
        }

        if (last_uniq_node == pre) {
            return nullptr;
        }
        else {
            last_uniq_node->next = nullptr;
        }
        
        return pre->next;
    }
};
