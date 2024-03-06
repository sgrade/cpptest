// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> lst;
        while (head) {
            if (lst.find(head) != lst.end())
                return true;
            lst.emplace(head);
            head = head->next;
        }
        return false;
    }
};
