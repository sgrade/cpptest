// 3063. Linked List Frequency
// https://leetcode.com/problems/linked-list-frequency/

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
    ListNode* frequenciesOfElements(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int, int> counter;
        ListNode* node = head;
        while (node) {
            ++counter[node->val];
            node = node->next;
        }
        head = new ListNode(0);
        ListNode* prev = head;
        for (const auto& [_, cnt]: counter) {
            node = new ListNode(cnt);
            prev->next = node;
            prev = node;
        }
        return head->next;
    }
};
