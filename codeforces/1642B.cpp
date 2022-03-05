// B. Power Walking

#include <iostream>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        set<int> cnt;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            cnt.insert(tmp);
        }

        int mx = size(cnt);

        for (int i = 1; i < n+1; ++i) {
            cout << max(mx, i) << ' ';
        }
        cout << '\n';

    }

    return 0;
}
