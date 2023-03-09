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


// SLOW
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while (head) {
            if (nodes.find(head) != nodes.end())
                return head;
            nodes.emplace(head);
            head = head->next;
        }
        return nullptr;
    }
private:
    unordered_set<ListNode*> nodes;
};
