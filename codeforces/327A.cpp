// A. Flipping Game

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) cin >> el;

    int ones_in_a = count(a.begin(), a.end(), 1);

    int ans = 0;
    
    int zeroes, ones, candidate;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ones = ones_in_a - count(a.begin() + j, a.begin() + i, 1);
            zeroes = count(a.begin() + j, a.begin() + i, 0);
            ans = max(ans, ones + zeroes);
        }
        for (int j = i + 1; j <= n; ++j) {
            ones = ones_in_a - count(a.begin() + i, a.begin() + j, 1);
            zeroes = count (a.begin() + i, a.begin() + j, 0);
            ans = max(ans, ones + zeroes);
        }
    }

    cout << ans << endl;

    return 0;
}
