// B. Getting Zero

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {

        int v;
        cin >> v;

        int ans = 32768 - v, cur_ans;

        int cur_v;
        
        for (int i = 0; i < 16; ++i) {
            cur_v = v + i;
            cur_ans = i;
            while (cur_v != 0) {
                cur_v = (2 * cur_v) % 32768;
                ++cur_ans;
            }
            ans = min(ans, cur_ans);
        }

        cout << ans << ' ';
    }
    
    cout << '\n';

    return 0;
}
