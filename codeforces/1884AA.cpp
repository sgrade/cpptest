// A. Simple Design

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, k;
        cin >> x >> k;

        long long y = max(x, k);
        while (true) {
            long temp = y, sum = 0LL;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum >= k && sum % k == 0) {
                cout << y << "\n";
                break;
            }
            ++y;
        }
        
    }

    return 0;
}
