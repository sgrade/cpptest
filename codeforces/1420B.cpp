// B. Rock and Lever

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (int i=0; i<n; ++i){
            cin >> v[i];
        }

        // touristream 012: Codeforces Round 672 (Div. 2)
        // https://www.youtube.com/watch?v=97tieEKfvBs

        vector<int> cnt(32, 0);
        for (int i=0; i<n; ++i){
            int bit = __builtin_clz(v[i]);
            cnt[bit] += 1;
        }

        long long ans = 0;
        // Tourist uses 32, but in the editorial comments I found the following:
        // Can anyone explain to me the problem b's code? why j from 29 to 0?
        // It is because 1<= Ai <=10^9. So Ai can have maximum length of 29 in binary form.
        for (int i=0; i<32; ++i){
            // n*(n-1)/2 - ariphmetic progression, which starts from 0 and increments by 1
            ans += (long long) cnt[i] * (cnt[i] - 1) / 2;
        }

        cout << ans << endl;

    }

    return 0;
}