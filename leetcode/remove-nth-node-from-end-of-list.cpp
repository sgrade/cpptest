// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include <unordered_map>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodes = 0;
        ListNode* node = head;
        while (node) {
            ++nodes;
            node = node->next;
        }

        nodes -= n;
        if (nodes == 0)
            return head->next;

        --nodes;
        node = head;
        while (nodes--)
            node = node->next;
        node->next = node->next->next;
        
        return head;
    }
};

