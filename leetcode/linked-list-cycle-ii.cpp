// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Floyd's Tortoise and Hare

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* intersect = GetIntersect(head);
        if (intersect == nullptr) {
            return nullptr;
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = intersect;
        
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }

private:
    ListNode* GetIntersect(ListNode* head) {
        ListNode* hare = head;
        ListNode* tortoise = head;
        
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return tortoise;
            }
        }
        
        return nullptr;
    }
};
