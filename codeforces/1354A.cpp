// A. Alarm Clock

#include <iostream>

using namespace std;
using ll = long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll ans = -1;

        if (a <= b) ans = b;
        else if (c > d){
            ans = b;
            a -= b;

            ll sleepCycleDuration = c - d;
            ll numOfCycles = (a + sleepCycleDuration - 1) / sleepCycleDuration;

            ans += numOfCycles * c;
        }

        cout << ans << endl;

    }

    return 0;
}
