// A. Three swimmers

#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long p;

unsigned long long check (unsigned long long x) {
    return ((p + x - 1) / x) * x - p;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        unsigned long long a, b, c;
        cin >> p >> a >> b >> c;

        a = check(a);
        b = check(b);
        c = check(c);

        cout << min({a, b, c}) << endl;
    }

    return 0;
}
