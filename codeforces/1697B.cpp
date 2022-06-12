// B. Promo

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> p[i];
    }

    sort(p.begin() + 1, p.end(), greater<int>());

    vector<long long> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        a[i] = a[i-1] + p[i];
    }
    
    int x, y, z;
    while (q--) {
        cin >> x >> y;
        z = x - y;
        cout << a[x] - a[z] << '\n';
    }

    return 0;
}
