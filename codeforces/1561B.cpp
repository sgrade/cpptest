// Charmed by the Game

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int total_games = a + b;

        vector<int> output;

        int min_brakes, max_brakes;
        min_brakes = abs(a - b) / 2;
        max_brakes = total_games - min_brakes;

        // If total_games is even, there cannot be even number of breaks
        int increment = total_games % 2 == 0 ? 2 : 1;

        for (int i = min_brakes; i <= max_brakes; i += increment) {
            output.push_back(i);
        }

        int ans = output.size();

        cout << ans << endl;
        for (auto &el: output) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
