// 641. Design Circular Deque
// https://leetcode.com/problems/design-circular-deque/

#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node* left;
    Node* right;
    int val;
    Node (int x) : val(x) {};
};


class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        this->k = k;
        size = 0;
    }

    bool insertFront(int value) {
        if (size == k)
            return false;
        Node* node = new Node(value);
        if (size == 0)
            back = node;
        else {
            node->right = front;
            front->left = node;
        }
        front = node;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (size == k)
            return false;
        Node* node = new Node(value);
        if (size == 0)
            front = node;
        else {
            node->left = back;
            back->right = node;
        }
        back = node;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;
        if (size == 1) {
            back = nullptr;
            front = nullptr;
        }
        else
            front = front->right;
        --size;
        return true;
    }

    bool deleteLast() {
        if (size == 0)
            return false;
        if (size == 1) {
            front = nullptr;
            back = nullptr;
        }
        else
            back = back->left;
        --size;
        return true;
    }

    int getFront() {
        if (size == 0)
            return -1;
        return front->val;
    }

    int getRear() {
        if (size == 0)
            return -1;
        return back->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == k;
    }

private:
    Node* front;
    Node* back;
    int k, size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
