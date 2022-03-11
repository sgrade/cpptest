// B. Dice Tower

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    long long x;
    int rem;

    while (t--) {

        cin >> x;

        bool ans = false;

        if (x > 14) {
            
            rem = x % 14;
            if (rem > 0 && rem < 7) {
                ans = true;
            }

        }
        
        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
