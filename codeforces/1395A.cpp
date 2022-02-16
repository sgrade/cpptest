// A. Boboniu Likes to Color Balls

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> balls(4);
bool ans;

bool palindrome () {

    int odd = 0;
    for (auto &el: balls) {
        if (el % 2 != 0) {
            ++odd;
        }
    }

    return (odd > 1 ? false : true);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
 
        for (auto &el: balls) {
            cin >> el;
        }    

        // Editorial - https://codeforces.com/blog/entry/81355

        ans = palindrome();

        if (!ans) {
            if (find(begin(balls), begin(balls)+3, 0) == begin(balls) + 3) {
                for (int i = 0; i < 3; ++i) {
                    --balls[i];
                }
                balls[3] += 3;
                ans = palindrome();
            }
        }

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}
