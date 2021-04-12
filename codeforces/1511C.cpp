// https://codeforces.com/contest/1511/problem/C

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;


int main() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &el: a) {
        cin >> el;
    }
    vector<int>::iterator ait;

    vector<int> ans(q);
    
    // Cache
    deque<int> c;
    deque<int>::iterator cit;

    int i = 0, x;
    while (q--) {
        cin >> x;

        cit = find(c.begin(), c.end(), x);
        if (cit != c.end()) {
            ans[i] = distance(c.begin(), cit);
            c.erase(cit);
            c.push_front(x);
        }

        else {
            ait = find(a.begin(), a.end(), x);
            ans[i] = c.size() + distance(a.begin(), ait);
            a.erase(ait);
            c.push_front(x);
        }

        ++i;            
    }

    for (auto &el: ans) {
        cout << el + 1 << ' ';
    }
    cout << endl;

    return 0;
}
