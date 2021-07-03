// D. Zero Remainder Array

#include <iostream>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        map<int, int> reminders;

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++reminders[tmp % k]; 
        }

        long long ans = 0;
        
        // Good explanation - https://www.youtube.com/watch?v=rFcDb79rJRw

        auto it = begin(reminders);
        if (it->first == 0) {
            ++it;
        }

        int rem, cnt;
        while (it != end(reminders)) {
            rem = it->first;
            cnt = it->second;
            ans = max(ans, 1LL * cnt * k - rem);
            ++it;
        }

        if (ans) {
            ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}
