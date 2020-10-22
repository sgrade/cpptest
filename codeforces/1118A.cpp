// A. Water Buying

#include <iostream>

using namespace std;


int main(){

    int q;
    cin >> q;

    while (q--){
        unsigned long long n, a, b;
        cin >> n >> a >> b;

        unsigned long long ans = 0;

        if (n == 1){
            ans = a;
        }
        else {
            if (a + a < b){
                ans = n*a;
            }
            else {
                ans = n/2 * b;
                if (n%2 != 0) ans += a;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
