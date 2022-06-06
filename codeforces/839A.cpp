// A. Arya and Bran

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // Editorial - https://codeforces.com/blog/entry/53815

    int candies = 0;
    int tmp;

    int ans = 1;
    for (; ans <= n; ++ans) {
        cin >> tmp; 
        candies += tmp;
        k -= min(candies, 8);
        candies -= min(candies, 8);
        if (k <= 0) break;
    }

    cout << (k <= 0 ? ans : -1) << '\n';

    return 0;
}
