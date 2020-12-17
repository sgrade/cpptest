// A. Party

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    // Editorial - https://codeforces.com/blog/entry/2584
    // Solution based on https://codeforces.com/contest/115/submission/57934041
    
    int p[n];
    for (auto &el: p) cin >> el;

    int ans = 0;
    for (int i = 0; i < n; ++i){
        int current = 0;
        int j = i;
        while (j >= 0){
            j = p[j] - 1;
            current += 1;
        }
        ans = max(ans, current);
    }

    cout << ans << endl;

    return 0;
}
