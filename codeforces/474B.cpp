// B. Worms

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el: a) cin >> el;

    int m, tmp;
    cin >> m;
    set<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        q.emplace(pair(tmp, i));
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        v.push_back(*v.rbegin() + 1);
        v.push_back(*v.rbegin() + a[i] - 1);
    }

    int index = 0;
    vector<int>::iterator it;
    vector<int> ans(m);
    for (auto el: q) {
        it = find_if(v.begin() + index, v.end(), [el](int x) {
            return el.first <= x;
        });
        index = distance(v.begin(), it);
        ans[el.second] = index / 2 + 1;
    }

    for (auto el: ans) {
        cout << el << endl;
    }

    return 0;
}
