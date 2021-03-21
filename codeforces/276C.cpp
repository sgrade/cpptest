// C. Little Girl and Maximum Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &el: a)
        cin >> el;
    sort(a.begin(), a.end(), greater<int>());
    
    int l, r;
    vector<int> cnt(n, 0);
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        // Idea - https://codeforces.com/blog/entry/6779
        ++cnt[l-1];
        if (r < n)
            --cnt[r];
    }

    multiset<int> st;
    int v = 0;
    for (int i = 0; i < n; ++i) {
        v += cnt[i];
        st.emplace(v);
    }

    unsigned long long sm = 0ULL;

    multiset<int>::reverse_iterator rit = st.rbegin();
    int i = 0;
    for (; i < n; ++i) {
        sm += 1ULL * a[i] * *rit;
        ++rit;
    }

    cout << sm << endl;

    return 0;
}
