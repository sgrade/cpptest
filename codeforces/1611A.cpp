// A. Make Even

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = -1;

        int last = n % 10;
        if (last % 2 == 0) {
            ans = 0;
        }

        else {
            int rem = n % 10;
            while(n != 0) {
                if (rem % 2 == 0) {
                    ans = 2;
                }
                rem = n % 10;
                n /= 10;
            }

            if (rem % 2 == 0) {
                ans = 1;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
