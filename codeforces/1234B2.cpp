// B2. Social Network (hard version)
// Same solution as for B1

#include <iostream>
#include <deque>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    deque<int> q;
    set<int> st;

    int tmp;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (st.find(tmp) == st.end()) {
            st.emplace(tmp);
            if (q.size() == k) {
                st.erase(q.front());
                q.pop_front();
            }
            q.push_back(tmp);
        }
    }

    cout << q.size() << '\n';

    while (!q.empty()) {
        cout << q.back() << ' ';
        q.pop_back();
    }
    cout << '\n';

    return 0;
}
