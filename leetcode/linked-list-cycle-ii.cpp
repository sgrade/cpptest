// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// Based on Leetcode's Approach 2: Floyd's Tortoise and Hare
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (head == nullptr) return nullptr;
        ListNode* intersect = GetIntersect(head);
        if (intersect == nullptr) return nullptr;

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
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) return tortoise;
        }
        return nullptr;
    }
};
