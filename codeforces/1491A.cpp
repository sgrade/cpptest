// A. K-th Largest Value

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    int sm = 0;
    for (auto &el: a) {
        cin >> el;
        sm += el;
    }

    int t, x, k, tmp;
    for (int i = 0; i < q; ++i) {
        cin >> t >> tmp;
        if (t == 1) {
            x = tmp - 1;
            a[x] = 1 - a[x];
            if (a[x] == 0) {
                sm -= 1;
            }
            else {
                sm += 1;
            }
        }
        else {
            k = tmp;
            if (k > sm) {
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
    }

    return 0;
}
