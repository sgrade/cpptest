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
        unordered_map<int, pair<ListNode*, ListNode*>> lst;
        ListNode *prev = new ListNode, *cur = head;
        prev->next = head;
        head = prev;
        int i = 1;
        while (cur) {
            lst[i] = {prev, cur->next};
            prev = cur;
            cur = cur->next;
            ++i;
        }
        n = i - n;
        lst[n].first->next = lst[n].second;
        return head->next;
    }
};
