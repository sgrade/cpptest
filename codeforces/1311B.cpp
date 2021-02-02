// B. WeirdSort

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        set<int> p;
        for (auto &el: a) cin >> el;
        int tmp;
        for (int i = 0; i < m; ++i) {
            cin >> tmp;
            p.emplace(tmp - 1);
        }

        // Editorial - https://codeforces.com/blog/entry/74224
        for (int i = 0; i < n; ++i) {
            if (p.find(i) != p.end()){
                int j = i;
                while (j < n && p.find(j) != p.end()){
                    ++j;
                }
                sort(a.begin() + i, a.begin() + j + 1);
                i = j;
            }
        }

        bool ans = is_sorted(a.begin(), a.end());

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
