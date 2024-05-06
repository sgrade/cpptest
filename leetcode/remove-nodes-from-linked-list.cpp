// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/

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
    ListNode* removeNodes(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nxt = head->next;
        while (current) {
            current->next = prev;
            prev = current;
            if (nxt) {
                current = nxt;
                nxt = current->next;
            }
            else
                break;
        }

        int current_max = 0;
        prev = nullptr;
        nxt = current->next;
        while (current) {
            if (current->val >= current_max) {
                current_max = current->val;
                current->next = prev;
                prev = current;
                if (nxt) {
                    current = nxt;
                    nxt = current->next;
                }
                else
                    break;
            }
            else {
                current = current->next;
                nxt = current ? current->next : nullptr;
            }
        }

        return prev;
    }
};
