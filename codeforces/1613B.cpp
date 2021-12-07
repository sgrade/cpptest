// B. Absent Remainder

#include <iostream>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        set<int, greater<int>> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }

        // Editorial - https://codeforces.com/blog/entry/97467
        int mn = *rbegin(a);

        auto it = begin(a);
        for (int i = 0; i < n/2; ++i) {
            cout << *it << ' ' << mn << '\n';
            ++it;
        }
    }

    return 0;
}
