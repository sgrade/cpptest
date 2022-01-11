// A. Death Note

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &el: a) {
        cin >> el;
    }

    int rem = 0, current;
    vector<int> output(n);
    for (int i = 0; i < n; ++i) {
        current = rem + a[i];
        output[i] = current / m;
        rem = current % m;
    }

    for (auto &el: output) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}
