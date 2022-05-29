// B. Z mod X = C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        ull a, b, c;
        cin >> a >> b >> c;

        // Editorial - https://codeforces.com/blog/entry/102995
        cout << a + b + c << ' ' << b + c << ' ' << c << '\n';
    }

    return 0;
}
