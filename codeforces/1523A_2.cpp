// A. Game of Life
// Time limit exceeded on pretest 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        string s;
        getline(cin >> ws, s);

        vector<bool> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] == '1' ? 1 : 0;
        }

        int tmp = m;
        auto it1 = find(begin(a), end(a), 1);
        
        if (it1 != end(a)) {
            int idx_it1 = distance(begin(a), it1);
            for (int i = idx_it1 - 1; i > -1 && tmp > 0; --i, --tmp) {
                a[i] = 1;
            }

            it1 = find(it1+1, end(a), 0);
            while (it1 != end(a)) {
                auto it2 = find(it1 + 1, end(a), 1);

                if (it2 != end(a)) {
                    int next_it1_idx = distance(begin(a), it2);

                    int d = distance(it1, it2);

                    if (d > 1) {
                        // Fill
                        d = min(d, m);
                        --it2;
                        while (it2 - it1 > 0 && d--) {
                            *it1 = 1;
                            *it2 = 1;
                            ++it1;
                            --it2;
                        }
                    }

                    it1 = find(begin(a) + next_it1_idx, end(a), 0);
                }

                else {
                    int dd = distance(begin(a), it1);
                    for (int i = dd; i < n && m > 0; ++i, --m) {
                        a[i] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i];
        }
        cout << endl;

    }

    return 0;
}
