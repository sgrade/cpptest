// A. Meaning Mean

#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        // Editorial - https://codeforces.com/blog/entry/134873
        for (int i = 1; i < a.size(); ++i)        
            a[i] = (a[i] + a[i - 1]) / 2;
        cout << a.back() << endl;
    }

    return 0;
}
