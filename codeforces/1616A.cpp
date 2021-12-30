// A. Integer Diversity

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        map<int, int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++a[tmp];
        }

        int ans = 0;
        for (auto &p: a) {
            if (p.first == 0) {
                ans += 1;
            }
            else {
                if (a.find(-p.first) != a.end()) {
                    ans += 1;
                }
                else {
                    ans += min(2, p.second);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
