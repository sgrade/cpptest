// 725. Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/

#include <bits/stdc++.h>

using namespace std;


// Optimized with Editorial's Approach #2: Split Input List [Accepted]

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {       
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        
        vector<ListNode*> ans;
        int len = n / k, rem = n % k;
        for (int i = 0; i < k; ++i) {
            ListNode* prev_head = head;
            int nodes = len + (i < rem ? 1 : 0);
            for (int j = 0; j < nodes - 1; ++j)
                head = head->next;
            if (head) {
                ListNode* prev = head;
                head = head->next;
                prev->next = nullptr;
            }
            ans.emplace_back(prev_head);
        }

        return ans;
    }
};
