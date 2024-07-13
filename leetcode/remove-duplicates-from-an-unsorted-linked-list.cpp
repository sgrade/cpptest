// 1836. Remove Duplicates From an Unsorted Linked List
// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, int> counter;
        ListNode* node = head;
        while (node) {
            ++counter[node->val];
            node = node->next;
        }

        node = head;
        ListNode* pre_head = new ListNode();
        pre_head->next = node;
        ListNode* prev = pre_head;
        while (node) {
            if (counter[node->val] > 1) {
                node = node->next;
                prev->next = node;
            }
            else {
                prev = node;
                if (node)
                    node = node->next;
            }
        }
        return pre_head->next;
    }
};
