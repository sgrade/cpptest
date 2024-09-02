// 1634. Add Two Polynomials Represented as Linked Lists
// https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/

#include <bits/stdc++.h>

using namespace std;


// Definition for polynomial singly-linked list.
struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};


class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        PolyNode* pre = new PolyNode;
        PolyNode* new_head = pre;
        PolyNode* current;
        while (poly1 || poly2) {
            if (poly1 && poly2) {
                if (poly1->power > poly2->power) {
                    current = poly1;
                    poly1 = poly1->next;
                }
                else if (poly1->power < poly2->power) {
                    current = poly2;
                    poly2 = poly2->next;
                }
                else {
                    int coefficient = poly1->coefficient + poly2->coefficient;
                    int power = poly1->power;
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                    if (coefficient != 0) {
                        current = new PolyNode (coefficient, power, nullptr);
                        pre->next = current;
                        pre = current;
                    }
                    continue;
                }
            }
            else if (poly1) {
                current = poly1;
                poly1 = poly1->next;
            }
            else {
                current = poly2;
                poly2 = poly2->next;
            }
            current->next = nullptr;
            pre->next = current;
            pre = current;
        }
        return new_head->next;
    }
};
