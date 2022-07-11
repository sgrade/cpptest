// C. Train and Queries

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        map<int, int> first, last;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (first.find(tmp) == first.end()){
                first[tmp] = i;
            }
            last[tmp] = i;
        }

        int a, b;
        for (int i = 0; i < k; ++i) {
            cin >> a >> b;
            if (first.count(a) && last.count(b) && first[a] <= last[b]) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
