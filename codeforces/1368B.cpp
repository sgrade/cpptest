// B. Codeforces Subsequences

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    unsigned long long k;
    cin >> k;

    string s = "codeforces";
    vector<int> cnt(10, 1);
    
    unsigned long long n = 1;
    while (n < k) {
        for (int i = 0; i < 10; ++i) {
            n /= cnt[i];
            ++cnt[i];
            n *= cnt[i];

            if (n >= k) {
                break;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < 10; ++i) {
        while(cnt[i]--) {
            ans += s[i];
        }
    }

    cout << ans << endl;

    // Good explanation - https://www.youtube.com/watch?v=HQnGixJMCiI
    // I found the solution myself though :)

    return 0;
}
