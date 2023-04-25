// 2336. Smallest Number in Infinite Set
// https://leetcode.com/problems/smallest-number-in-infinite-set/

#include <bits/stdc++.h>

using namespace std;


class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        lst.emplace_front(1, numeric_limits<int>::max());
    }

    int popSmallest() {
        int mn = lst.front().first;
        if (lst.front().first == lst.front().second) {
            lst.erase(lst.begin());
        }
        else {
            ++lst.front().first;
        }
        return mn;
    }
    
    void addBack(int num) {
        if (lst.empty()) {
            lst.emplace_front(num, num);
        }

        auto it = find_if (lst.begin(), lst.end(), [num](const pair<int, int> p){
            return p.first <= num && num <= p.second;
        });
        if (it != lst.end()) {
            return;
        }
        
        it = lower_bound(lst.begin(), lst.end(), pair<int, int>(num, num));

        if (it == lst.begin()) {
            if (it->first - 1 == num) {
                --it->first;
            }
            else {
                lst.emplace_front(num, num);
            }
            return;
        }

        if (it == lst.end()) {
            it = prev(it);
            if (it->second + 1 == num) {
                ++it->second;
            }
            else {
                lst.emplace_back(num, num);
            }
            return;
        }

        if (it->first - 1 == num) {
            --it->first;
            return;
        }
        if (prev(it)->second + 1 == num) {
            ++prev(it)->second;
            return;
        }
        lst.emplace(it, num, num);
    }

private:
    list<pair<int, int>> lst;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
