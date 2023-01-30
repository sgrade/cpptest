// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach #3 (One Queue, push - O(n)O(n)O(n), pop O(1)O(1)O(1) )
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.emplace(x);
        int len = q.size();
        while (len > 1) {
            q.emplace(q.front());
            q.pop();
            --len;
        }
    }
    
    int pop() {
        int frnt = q.front();
        q.pop();
        return frnt;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    int top_element;
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
