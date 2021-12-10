// A. Candies

#include <iostream>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    int mn, rem;
    mn = n / m;
    rem = n % m;

    int i;
    for (i = 0; i < rem; ++i) {
        cout << mn + 1 << ' ';
    }
    for (; i < m; ++i) {
        cout << mn << ' ';
    }
    cout << endl;

    return 0;
}
