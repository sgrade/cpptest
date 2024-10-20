// B. Minimise Oneness

#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        for (int i = 0; i < n; ++i)
            s += '0';
        if (n % 2 == 0)
            s[0] = '1';
        else
            s[n / 2] = '1';
        
        cout << s << endl;
    }

    return 0;
}
