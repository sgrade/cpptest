// 622. Design Circular Queue
// https://leetcode.com/problems/design-circular-queue/

#include <bits/stdc++.h>

using namespace std;


class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (main_q.size() == k) {
            return false;
        }
        main_q.emplace_back(value);
        return true;
    }
    
    bool deQueue() {
        if (main_q.empty()) {
            return false;
        }
        main_q.pop_front();
        return true;
    }
    
    int Front() {
        if (main_q.empty()) {
            return -1;
        }
        return main_q.front();
    }
    
    int Rear() {
        if (main_q.empty()) {
            return -1;
        }
        return main_q.back();
    }
    
    bool isEmpty() {
        return main_q.empty();
    }
    
    bool isFull() {
        return main_q.size() == k;
    }

private:
    int k;
    list<int> main_q;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
