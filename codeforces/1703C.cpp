// C. Cypher

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        for (int i = 0; i < n; ++i) {

            int b;
            cin >> b;

            string s;
            cin >> s;

            for (int j = 0; j < b; ++j) {
                if (s[j] == 'U') {
                    --a[i];
                }
                else {
                    ++a[i];
                }
                if (a[i] == -1) {
                    a[i] = 9;
                }
                else if (a[i] == 10) {
                    a[i] = 0;
                }
            }
        }

        for (const int &el: a) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
