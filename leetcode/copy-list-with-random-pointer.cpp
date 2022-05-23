// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        
        Node* current = head;
        while(current) {
            Node* copy = new Node(current->val);
            mp[current] = copy;
            current = current->next;
        }
        
        current = head;
        while(current) {
            Node* copy = mp[current];
            copy->next = mp[current->next];
            copy->random = mp[current->random];
            current = current->next;
        }
        
        return mp[head];
    }
};
