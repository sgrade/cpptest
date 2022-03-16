// A. Heating

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {

        int c, sum;
        cin >> c >> sum;

        // Sections per radiator
        int base = sum / c;
        // Reminder
        int rem = sum % c;

        long long ans = 0;

        if (rem != 0) {
            ans += 1LL * rem * (base + 1) * (base + 1);
            c -= rem;
        }

        ans += 1LL * c * base * base;

        cout << ans << '\n';
    }

    return 0;
}
