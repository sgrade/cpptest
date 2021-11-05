// C. Di-visible Confusion

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        bool ans = true;
     
        int tmp;
        for (int i = 1; i < n+1; ++i) {
            cin >> tmp;
            if (!ans) {
                continue;
            }
            bool flag = false;
            for (int j = 2; j < i+2; ++j) {
                if (tmp % j != 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

        //Editorial - https://codeforces.com/blog/entry/96460

    }

    return 0;
}
