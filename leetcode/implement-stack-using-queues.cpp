// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>

using namespace std;


class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        top_element = x;
        q.emplace(x);
    }
    
    int pop() {
        int len = q.size();
        
        while (len > 2) {
            q.emplace(q.front());
            q.pop();
            --len;
        }

        int frnt = q.front();

        if (q.size() == 2) {
            top_element = frnt;
            q.emplace(q.front());
            q.pop();
        }

        frnt = q.front();
        q.pop();
        
        return frnt;
    }
    
    int top() {
        return top_element;
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
