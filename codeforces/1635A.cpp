// A. Min Or Sum

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

        int n;
        cin >> n;

        int ans, tmp;
        cin >> ans;

        for (int i = 1; i < n; ++i) {
            cin >> tmp;
            ans |= tmp;
        }

        cout << ans << '\n';
    }



    return 0;
}
