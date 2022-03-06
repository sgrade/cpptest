// B. Yet Another Meme Problem

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int A, B;
        cin >> A >> B;

        // Editorial - https://codeforces.com/blog/entry/73105

        int len_B = 0;
        ++B;
        while (B != 0) {
            B /= 10;
            ++len_B;
        }

        long long ans = 1LL * A * (len_B - 1);

        cout << ans << '\n';
    }

    return 0;
}
