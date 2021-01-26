// C. Ball in Berland

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b, k;
        cin >> a >> b >> k;

        vector<int> boys(a), girls(b);
        vector<pair<int, int>> pairs(k);

        // Editorial - https://codeforces.com/blog/entry/87188

        for (auto &[boy, girl]: pairs) cin >> boy;
        for (auto &[boy, girl]: pairs) cin >> girl;
        for (auto &[boy, girl]: pairs) {
            --boy;
            --girl;
            ++boys[boy];
            ++girls[girl];
        }

        unsigned long long ans = 0;

        for (auto &[boy, girl]: pairs) {
            ans += k - (boys[boy] + girls[girl] - 1);
        }

        cout << ans / 2 << endl;

    }

    return 0;
}
