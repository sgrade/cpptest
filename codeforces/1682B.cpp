// B. AND Sorting

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int ans;
        
        int tmp;

        int i = 0;
        for (; i < n; ++i) {
            cin >> tmp;
            if (tmp != i) {
                ans = tmp;
                ++i;
                break;
            }
        }

        for (; i < n; ++i) {
            cin >> tmp;
            if (tmp != i) {
                ans &= tmp;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
