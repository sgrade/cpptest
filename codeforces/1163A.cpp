// A. Eating Soup

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ans = 1;

    if (m > 0) {
        ans = min(m, n - m);
    }

    cout << ans << endl;

    return 0;
}
