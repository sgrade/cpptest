// B. Triple

#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int tmp;
        map<int, int> a;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++a[tmp];
        }

        int ans = 0;
        for (auto &p: a) {
            if (p.second > 2) {
                ans = p.first;
                break;
            }
        }

        if (ans > 0) cout << ans;
        else cout << "-1";

        cout << '\n';
    }

    return 0;
}
