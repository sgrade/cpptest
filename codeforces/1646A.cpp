// A. Square Counting

#include <iostream>

using namespace std;
using ull = unsigned long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)  {

        ull n, s;
        cin >> n >> s;

        ull n2 = n * n;

        ull ans = s / n2;

        cout << ans << '\n';
    }

    return 0;
}
