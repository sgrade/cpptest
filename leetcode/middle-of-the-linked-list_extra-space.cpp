// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.emplace_back(head);
            head = head->next;
        }
        return nodes[nodes.size() / 2];
    }
};
