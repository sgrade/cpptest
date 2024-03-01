// 3062. Winner of the Linked List Game
// https://leetcode.com/problems/winner-of-the-linked-list-game/

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
    string gameResult(ListNode* head) {
        int sum = 0;
        while (head) {
            if (head->val != head->next->val)
                sum += head->val > head->next->val ? 1 : -1;
            head = head->next->next;
        }
        if (sum == 0)
            return "Tie";
        return sum > 0 ? "Even" : "Odd";
    }
};
