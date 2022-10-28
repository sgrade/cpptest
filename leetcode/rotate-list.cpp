// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        int n = 0;
        ListNode* current = head;
        while (current) {
            ++n;
            current = current -> next;
        }
        
        k %= n;
        if (k == 0) {
            return head;
        }
        
        current = head;
        n -= k;
        while (--n) {
            current = current -> next;
        }
        
        ListNode* ans = current->next;
        current->next = nullptr;
        current = ans;
        while (current->next) {
            current = current->next;
        }
        current->next = head;
        
        return ans;
    }
};
