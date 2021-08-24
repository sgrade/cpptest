// Charmed by the Game
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    vector<vector<int>> dp(200000, vector<int>(2));
    for (int i = 1; i <= 200000; ++i) {
        // Alice serves first
        dp[i-1][0] += 1;
        // Boris serves first
        dp[i-1][1] += 1;
    }

    while (t--) {

        int a, b;
        cin >> a >> b;

        int games = a + b;

        vector<int> ans;

        int max_receives;
        for (int g = 1; g <= games; ++g) {
            max_receives = (g + 2 - 1) / 2;
        }

    }

    return 0;
}
